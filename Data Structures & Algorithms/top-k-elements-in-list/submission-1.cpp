class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq ;
        for( const int& num : nums){
            freq[num] ++;
        }

        // create a vector, where the index == frequency
        vector<vector<int>> occ (nums.size()+1);

        // populate the occ vector
        for (const auto& [k,v] : freq){
            occ[v].push_back(k);
        }

        // now we iterate through occ starting from the end
        vector<int> res;
        int q = k;
        for(int i = nums.size(); i>=0 && q>0; i--  ){
            for(int p = 0; p<occ[i].size(); p++){
                res.push_back(occ[i][p]);
                q--;
            }
        }
        return res;

    }   
};