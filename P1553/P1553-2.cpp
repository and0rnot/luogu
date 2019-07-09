#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void RemoveHead0(string& s) {
    int zero_num = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') 
            zero_num++;
		else 
            break;
	}
	
    s.erase(s.begin(), s.begin() + zero_num);
    if (s == "") // if empty, fill 0 at least
        s = "0";
}

void RemoveTail0(string& s) {
    int zero_num = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '0') 
            zero_num++;
		else 
            break;
	}
    s.erase(s.end() - zero_num, s.end());
    if (s == "")
        s = "0";
}

void ProcessDecimal(string& s) {
    string left, right;
    int pos = s.find(".");
    left = s.substr(0, pos);
    right = s.substr(pos+1);

    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());

    RemoveHead0(left);
    RemoveTail0(right);
    cout << left << "." << right << endl;
}

void ProcessFraction(string& s) {
    string left, right;
    int pos = s.find("/");
    left = s.substr(0, pos);
    right = s.substr(pos+1);

    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());

    RemoveHead0(left);
    RemoveHead0(right);
    
    cout << left << "/" << right << endl;
}

void ProcessPercentage(string& s) {
    string left;
    int pos = s.find("%");
    left = s.substr(0, pos);
    reverse(left.begin(), left.end());
    RemoveHead0(left);
    cout << left << "%" << endl;
}

void ProcessInt(string& s) {
    reverse(s.begin(), s.end());
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