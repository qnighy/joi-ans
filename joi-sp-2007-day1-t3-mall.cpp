/*
 * Problem: joi-sp-2007-day1-t3-mall
 * Author: Masaki Hara
 * O(NM)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int m,n,a,b; scanf("%d%d%d%d", &m, &n, &a, &b);
  static long long sum[1001][1001];
  long long min_val = 300000000000000LL;
  for(int y = 0; y <= n; y++) {
    for(int x = 0; x <= m; x++) {
      if(x==0 || y==0) {
        sum[y][x] = 0;
      } else {
        scanf("%lld", &sum[y][x]);
        if(sum[y][x]==-1) sum[y][x]=200000000;
        sum[y][x] += sum[y-1][x] + sum[y][x-1] - sum[y-1][x-1];
      }
      if(y>=b && x>=a) {
        min_val = min(min_val,
            sum[y][x] - sum[y-b][x] - sum[y][x-a] + sum[y-b][x-a]
            );
      }
    }
  }
  printf("%lld\n", min_val);
  return 0;
}
