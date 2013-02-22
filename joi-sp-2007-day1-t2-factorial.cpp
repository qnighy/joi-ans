/*
 * Problem: joi-sp-2007-day1-t2-factorial
 * Author: Masaki Hara
 * O(N^(1/2))
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  int m = 1;
  for(int p = 2; p*p <= n; p++) {
    if(n%p) continue;
    int e = 0;
    do { e++; n/=p; } while(n%p==0);
    for(int q = p;; q+=p) {
      int qd = q;
      do { e--; qd/=p; } while(qd%p==0);
      if(e<=0) {
        m = max(m,q);
        break;
      }
    }
  }
  printf("%d\n", max(m,n));
  return 0;
}
