
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    else return 2;
}

int solve(int val1, int val2, char op) {
    if (op == '+') return val1 + val2;
    else if (op == '-') return val1 - val2;
    else if (op == '*') return val1 * val2;
    else if (op == '/') return val1 / val2;
    return 0;
}

// Infix expression
int main() {
    string s = "2+6*4/8-3";
    stack<int> val;
    stack<char> opr;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 48 && s[i] <= 57) { // ASCII value of numbers
            val.push(s[i] - 48);
        } else {
            if (opr.size() == 0) opr.push(s[i]);
            else if (priority(opr.top()) < priority(s[i])) {
                opr.push(s[i]);
            } else {
                while (!opr.empty() && priority(opr.top()) >= priority(s[i])) {
                    char op = opr.top();
                    opr.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, op);
                    val.push(ans);
                }
                opr.push(s[i]);
            }
        }
    }

    // The opr stack can have some values
    while (opr.size() > 0) {
        char op = opr.top();
        opr.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, val2, op);
        val.push(ans);
    }

    cout << val.top();
    return 0;
}
