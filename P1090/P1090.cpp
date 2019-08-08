#include <iostream>
#include <algorithm>
using namespace std;

int apple[10001];
int cnt;

void insert(int num) {
    cnt++;
    apple[cnt] = num;
    push_heap(apple+1, apple+1+cnt, greater<int>());
}

int pop() {
    int a = apple[1];
    pop_heap(apple+1, apple+1+cnt, greater<int>());
    cnt--;
    return a;
}
int main() {
    cin >> cnt;
    for (int i = 1; i <= cnt; i++) {
        cin >> apple[i];
    }

    make_heap(apple+1, apple+1+cnt, greater<int>());
    long ans = 0;
    while (cnt > 1) {
        int s1 = pop();
        int s2 = pop();
        ans += s1+s2;
        insert(s1+s2);
    }
    cout << ans << endl;
    return 0;
}
