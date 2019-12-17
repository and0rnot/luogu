#include <iostream>
#include <algorithm>
using namespace std;

bool debug = false;

int main() {
  const int kMax = 10000;
  int seq[kMax+1];

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> seq[i];

  int ans = 0;
  for (int i = 1; i < N; i++) {
    for (int j = i+1; j <= N; j++ ) {
      if (seq[i] > seq[j]) {

        // int tmp = seq[i];
        // seq[i] = seq[j];
        // seq[j] = tmp;
        std::swap(seq[i], seq[j]);
        ans++;
      }
    }
  }
  cout << ans << endl;

  if (debug) {
    for (int i = 1; i <= N; i++) {
      cout << seq[i] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
