#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

stack<char> ops;
stack<int> number;

void Compute() {
    int left, right;
    
    right = number.top();
    number.pop();
    left = number.top();
    number.pop();

    char op = ops.top();
    ops.pop();
    
    // careful for (2^31 - 1) * (2^31 - 1)
    long long ret = 0;
    if (op == '+') {
        ret = left + right;
    } else if (op == '*') {
        ret = left * right;   
    }
    number.push(ret%10000);
    //cout << "op " << op << "push " << ret << endl;
}

bool IsOpHigh(char op) {
    if (ops.empty())
        return true;

    if (ops.top() == '+' && op == '*')
        return true;

    return false;
}

int main() {
    string s;
    getline(cin, s);

    // add tail flag
    int now_int = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '*') {
            //cout << now_int << endl;
            number.push(now_int%10000); // push one int now
            now_int = 0; // clear

            //cout << s[i] << endl;
            if (IsOpHigh(s[i])) {
                ops.push(s[i]);
            } else {
                while (!IsOpHigh(s[i])) {
                    Compute();
                }
                ops.push(s[i]);
            }
        } else {
            if (isdigit(s[i])) {
                now_int = now_int*10 + s[i] - '0';
                if (i == s.size() - 1)
                    number.push(now_int%10000);
            }
        }
    }

    while (!ops.empty()) {
        Compute();
    }

    // if (2^31 - 1) * (2^31 - 1)
    long long result = number.top();
    number.pop();
    cout << result % 10000 << endl;

    return 0;
}