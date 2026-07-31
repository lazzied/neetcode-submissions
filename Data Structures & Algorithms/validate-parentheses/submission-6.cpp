#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        int n = s.length();
        stack<char> st;

        vector<char> start = {'(', '{', '['};

        if (n == 0) {
            return false;
        }

        if (n % 2 != 0) {
            return false;
        }

        for (int i = 0; i < n; i++) {

            if (find(start.begin(), start.end(), s[i]) != start.end()) {
                st.push(s[i]);
            }
            else {

                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                if (s[i] == ')') {
                    if (top != '(') {
                        return false;
                    }
                }
                else if (s[i] == '}') {
                    if (top != '{') {
                        return false;
                    }
                }
                else if (s[i] == ']') {
                    if (top != '[') {
                        return false;
                    }
                }

                st.pop();
            }
        }

        return st.empty();
    }
};