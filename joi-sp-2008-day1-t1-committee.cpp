/*
 * Problem: joi-sp-2008-day1-t1-committee
 * Author: Masaki Hara
 * O(N)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int N; scanf("%d", &N);
  static int s[100000],a[100000];
  for(int i = 0; i < N; i++) {
    scanf("%d%d", s+i, a+i); s[i]--;
  }
  int ans = -10000000;
  for(int i = N-1; i >= 0; i--) {
    ans = max(ans, a[i]);
    if(i>0 && a[i]>0) a[s[i]]+=a[i];
  }
  printf("%d\n", ans);
  return 0;
}
