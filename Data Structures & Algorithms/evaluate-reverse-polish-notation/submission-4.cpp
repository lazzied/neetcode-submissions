class Solution {
public:
    int applyOp(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
                if (b == 0) throw std::runtime_error("Division by zero");
                return a / b;
            default: throw std::invalid_argument("Unknown operator");
        }
    }
    bool isInteger(string s) {

    if (s.empty())
        return false;

    int start = 0;

    if (s[0] == '+' || s[0] == '-') {
        start = 1;
    }

    if (start == s.length())
        return false;

    for (int i = start; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }

    return true;
}
    int evalRPN(vector<string>& tokens) {
        stack<int> stk ;

        for (string c : tokens){
            if (isInteger(c)){
                stk.push(stoi(c));
            }
            else{ // after an op character, there should onle be one element remaining in the stack
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(applyOp(b,a,c[0]));

            }
        }
        return stk.top();
        
    }
};
