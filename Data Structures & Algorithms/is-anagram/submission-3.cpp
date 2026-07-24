class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;  // quick early exit

        unordered_map<char,int> s_string;
        unordered_map<char,int> t_string;

        for (int i = 0; i < s.length(); i++) {
            s_string[s[i]]++;   // increments count (creates with 0 first time, then +1)
        }
        for (int i = 0; i < t.length(); i++) {
            t_string[t[i]]++;
        }

        return s_string == t_string;
    }
};