/*
 * Problem: joi-sp-2007-day2-t2-fermat
 * Author: Masaki Hara
 * O(p log N)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int p,N; scanf("%d%d", &p, &N);
  int nb; for(nb=0; (1<<nb)<N; nb++);

  static int rootcnt[10000];
  for(int x = 0; x < p; x++) {
    int xn = 1;
    for(int i = nb; i >= 0; i--) {
      xn = xn*xn%p;
      if((N>>i)&1) xn = xn*x%p;
    }
    rootcnt[xn]++;
  }
  long long m = 0;
  for(int xn = 0; xn < p; xn++) {
    m += 1L*rootcnt[xn]*(rootcnt[xn]+(p-1)*rootcnt[(xn+1)%p]);
  }
  printf("%lld\n", m);
  return 0;
}
