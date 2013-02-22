/*
 * Problem: joi-sp-2007-day2-t1-building
 * Author: Masaki Hara
 * O(N log N)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int N; scanf("%d", &N);
  static int lis[1001];
  fill(lis+1, lis+N+1, 10001);
  lis[0] = -1;
  for(int i = 0; i < N; i++) {
    int ai; scanf("%d", &ai);
    lower_bound(lis, lis+N+1, ai)[0] = ai;
  }
  for(int i = 0; i <= N; i++) {
    if(i==N || lis[i+1] == 10001) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
