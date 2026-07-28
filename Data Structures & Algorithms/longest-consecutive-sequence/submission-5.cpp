class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sorting is O nlogn 
        if (nums.empty()){
            return 0;
        }
        unordered_map<int,vector<int>> sequences;
        for (int i = 0; i<nums.size() ; i++){
            sequences[nums[i]] = {};
        };
        int maxLength = 0;
        for (auto& [start,seq] : sequences){
            int next = start + 1;
            while (sequences.find(next) != sequences.end()){
                sequences[start].push_back(next);
                next ++;
            }
            int seqLength =  sequences[start].size();
            if (seqLength> maxLength){
                maxLength = seqLength; 
            };
        };
        // start + seqLength
        return maxLength + 1; 
        
    };
};
