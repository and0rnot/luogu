#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

uint bkdr_hash(string s) {
    uint seed = 131;
    uint hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash = hash*seed + s[i];
    }
    return hash&0x7fffffff;
}

uint a[10001];

int main() {
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        int pos = bkdr_hash(s);
        a[i] = pos;
    }

    sort(a+1, a+N+1); // ascending sort

    int ans = 1;
    for (int i = 2; i <= N; i++) {
        if (a[i] != a[i-1])
            ans++;
    }

    cout << ans << endl;
}