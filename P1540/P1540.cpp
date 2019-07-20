#include <iostream>
#include <queue>
using namespace std;

queue<int> mem;
bool exist[1001]; // check if in memory

void insert(int now, int M) {
    if (mem.size() == M) {
        exist[mem.front()] = false;
        mem.pop();
        mem.push(now);
    } else {
        mem.push(now);
    }
    exist[now] = true;
}

int main() {
    int M, N;
    cin >> M >> N;

    int check_num = 0;
    for (int i = 1; i <= N; i++) {
        int now;
        cin >> now;
        if (!exist[now]) {
            insert(now, M);
            check_num++;
        }
    }
    cout << check_num << endl;
    return 0;
}