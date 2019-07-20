#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<char> left;

    string s;
    getline(cin, s);

    bool match = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '@') {
            break;
        } else if (s[i] == '(') {
            left.push(s[i]);
        } else if (s[i] == ')') {
            if (left.empty()) { // ')' more
                match = false;
                break;
            }
            left.pop();
        }
    }

    if (!left.empty()) // '(' more
        match = false;

    if (match)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}