/*
 * Problem: joi-sp-2008-day2-t2-cheating
 * Author: Masaki Hara
 * O((M+N)logX)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int N,M; scanf("%d%d", &N, &M);
  static int x[100000],y[100000];
  for(int i = 0; i < M; i++) {
    scanf("%d%d", x+i,y+i);
  }
  sort(x,x+M);
  sort(y,y+M);
  int lb=-1,ub=1000000000;
  while(ub-lb>1) {
    int d = (lb+ub)/2;
    int cnt = 0;
    int l = -1;
    for(int i = 0; i < M; i++) {
      if(l<x[i]) {
        cnt++;
        l = x[i]+d;
      }
    }
    l = -1;
    for(int i = 0; i < M; i++) {
      if(l<y[i]) {
        cnt++;
        l = y[i]+d;
      }
    }
    if(cnt <= N) ub=d; else lb=d;
  }
  printf("%d\n", ub);
  return 0;
}
