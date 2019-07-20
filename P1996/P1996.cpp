#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> q;

    for (int i = 1; i <= n; i++)
        q.push(i);

    int now = 1;
    while (!q.empty()) {
        if (now == m) {
            now = 1;
            cout << q.front() << " ";
            q.pop();
        } else {
            now++;
            // move from head to tail
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    cout << endl;
    return 0;
}