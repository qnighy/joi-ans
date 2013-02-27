/*
 * Problem: joi-sp-2008-day2-t1-nile
 * Author: Masaki Hara
 * O(ND)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int N,D; scanf("%d%d", &N, &D);
  int (*dp1)[3] = new int[N][3];
  int (*dp2)[3] = new int[N][3];
  int minval = 100000000;
  for(int j = 0; j < N; j++) {
    scanf("%d", &dp1[j][0]);
    dp1[j][1] = dp1[j][2] = 100000000;
    minval = min(minval, dp1[j][0]);
  }
  for(int i = 1; i < D; i++) {
    for(int j = 0; j < N; j++) {
      int x; scanf("%d", &x);
      dp2[j][0] = minval + x;
      dp2[j][1] = dp1[j][0] + x*9/10;
      dp2[j][2] = min(dp1[j][2], dp1[j][1]) + x*7/10;
    }
    swap(dp1,dp2);
    minval = 100000000;
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < 3; k++) {
        minval = min(minval, dp1[j][k]);
      }
    }
  }
  delete[] dp1;
  delete[] dp2;
  printf("%d\n", minval);
  return 0;
}
