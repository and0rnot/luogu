#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string plain;
    char pwd[50] = "";
    cin >> plain;
    for (int i = 0; i < plain.size(); i++) {
        pwd[i] = (plain[i] - 'a' + n) % 26 + 'a';
    }
    cout << pwd << endl;

    return 0;
}