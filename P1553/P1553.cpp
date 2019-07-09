#include <iostream>
#include <string>
using namespace std;

void Revert(string& s) {
    char c;
    for (int i = 0; i < s.size()/2; i++) {
        c = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = c;
    }
}

// note: it can be many 0 like "000"
void RemoveHead0(string& s) {
    int i = 0;
    // overlook head 0
    while (s[i] == '0' && i < s.size())
        i++;
    
    if (i == s.size())
        s = "0";
    else
        s = s.substr(i);
}

void RemoveTail0(string& s) {
    int i = s.size() - 1;
    // overlook tail 0
    while (s[i] == '0' && i >= 0)
        i--;
    
    if (i < 0)
        s = "0";
    else
        s = s.substr(0, i+1);
}

void ProcessDecimal(string& s) {
    string left, right;
    int pos = s.find(".");
    left = s.substr(0, pos);
    right = s.substr(pos+1);

    Revert(left);
    Revert(right);

    RemoveHead0(left);
    RemoveTail0(right);
    cout << left << "." << right << endl;
}

void ProcessFraction(string& s) {
    string left, right;
    int pos = s.find("/");
    left = s.substr(0, pos);
    right = s.substr(pos+1);

    Revert(left);
    Revert(right);

    RemoveHead0(left);
    RemoveHead0(right);
    
    cout << left << "/" << right << endl;
}

void ProcessPercentage(string& s) {
    string left;
    int pos = s.find("%");
    left = s.substr(0, pos);
    Revert(left);
    RemoveHead0(left);
    cout << left << "%" << endl;
}

void ProcessInt(string& s) {
    Revert(s);
    RemoveHead0(s);
    cout << s << endl;
}

int main() {
    string all;
    cin >> all;
    if (all.find(".") != string::npos) {
        ProcessDecimal(all);
    } else if (all.find("/") != string::npos) {
        ProcessFraction(all);
    } else if (all.find("%") != string::npos) {
        ProcessPercentage(all);
    } else {
        ProcessInt(all);
    }
    return 0;
}