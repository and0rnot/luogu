#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cow[20001] = {0};
    int N;
    long long B;

    cin >> N >> B;
    for (int i = 1; i <= N; i++)
        cin >> cow[i];

    sort(cow+1, cow+1+N, greater<int>());

    long long sum = 0;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        sum += cow[i];
        ans++;
        if (sum > B)
            break;
    }

    cout << ans << endl;
    return 0;
}