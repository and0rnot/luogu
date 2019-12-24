#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101;
int map[N][N];
int n, m, k;

bool valid(int x, int y) {
  if (x < 1 || y < 1 || x > n || y > n)
    return false;
  return true;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= m+k; i++) { // torch + stone
      int a, b;
      cin >> a >> b;

      for (int x = -2; x <= 2; x++) {
        for (int y = -2; y <= 2; y++) {
          if ((i > m || abs(x)+abs(y)<=2) && valid(x+a, y+b)) {
            map[x+a][y+b] = 1;
          }
        }
      }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        //cout << map[i][j] << " ";
        if (map[i][j] == 0)
          ans++;
      }
      //cout << endl;
    }
    cout << ans << endl;

    return 0;
}
