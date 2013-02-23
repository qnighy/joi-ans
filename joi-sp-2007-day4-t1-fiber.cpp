/*
 * Problem: joi-sp-2007-day4-t1-fiber
 * Author: Masaki Hara
 * O(N+Malpha(N)) where alpha is reverse Ackermann
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct UF {
  vector<int> p;
  UF(int N) : p(N,-1) {}
  int rt(int x) { return p[x]<0?x:p[x]=rt(p[x]); }
  bool cat(int x, int y) {
    if((x=rt(x))==(y=rt(y))) return false;
    if(p[x]<p[y]) swap(x,y);
    p[y]+=p[x]; p[x]=y; return true;
  }
};

int main() {
  int N,M; scanf("%d%d", &N, &M);
  int cnt = N;
  UF uf(N);
  for(int i = 0; i < M; i++) {
    int a,b; scanf("%d%d", &a, &b); a--; b--;
    if(uf.cat(a,b)) cnt--;
  }
  printf("%d\n", cnt-1);
  return 0;
}

