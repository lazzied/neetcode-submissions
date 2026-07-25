class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int>, vector<string>> res;

        for (const string &str : strs) {
            vector<int> rep(26, 0);

            for (char c : str) {
                rep[c - 'a']++;
            }

            res[rep].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto &p : res)
            ans.push_back(p.second);

        return ans;
    }
};