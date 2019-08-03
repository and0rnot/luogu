//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

typedef struct FBI_Node {
    char c;
    FBI_Node* left;
    FBI_Node* right;
} FBI_Node;

char GetRoot(string s) {
    if (s.find('0') != string::npos && s.find('1') != string::npos)
        return 'F';
    if (s.find('0') != string::npos)
        return 'B';
    
    return 'I';
}

void BuildFBI(FBI_Node* t, string s) {
    t->c = GetRoot(s);
    if (s.size() > 1) {
        string s1 = s.substr(0, s.size()/2);
        string s2 = s.substr(s.size()/2);
        t->left = new FBI_Node;
        BuildFBI(t->left, s1);
        t->right = new FBI_Node;
        BuildFBI(t->right, s2);
    }
}

// Post Order
void Output(FBI_Node* t) {
    if (t == NULL)
        return;

    Output(t->left);
    Output(t->right);
    cout << t->c;
}

int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    FBI_Node* root = new FBI_Node;
    BuildFBI(root, str);
    Output(root);
    cout << endl;
    return 0;
}