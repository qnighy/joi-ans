/*
 * Problem: joi-sp-2008-day1-t3-flu
 * Author: Masaki Hara
 * O(N(2d)^2 + WH)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int N,M,D,K; scanf("%d%d%d%d", &N, &M, &D, &K);
  int yd[50];
  for(int x = -D; x <= D; x++) {
    for(int y = 0; x*x+y*y <= D*D; y++) {
      yd[x+25] = y;
    }
  }
  static bool tbl[1050][1050];
  for(int i = 0; i < 1050; i++) fill(tbl[i],tbl[i]+1050,false);
  int sx,sy; scanf("%d%d", &sx, &sy); sx+=25; sy+=25;
  for(int i = 1; i < N; i++) {
    int x,y; scanf("%d%d", &x, &y); x+=25; y+=25;
    tbl[x][y] = true;
  }
  static pair<int,pair<int,int> > q[100000];
  int qs=0,qe=0;
  q[qe++] = make_pair(0,make_pair(sx,sy));
  int count = 0;
  while(qs<qe) {
    pair<int,pair<int,int> > v = q[qs++];
    if(v.first > K) break;
    if(v.first > K-M) count++;
    // fprintf(stderr, "(%d,%d): %d\n",
    //     v.second.first-25, v.second.second-25, v.first);
    for(int x = -D; x <= D; x++) {
      int dd = yd[25+x];
      for(int y = -dd; y <= dd; y++) {
        if(!tbl[v.second.first+x][v.second.second+y]) continue;
        tbl[v.second.first+x][v.second.second+y] = false;
        q[qe++] = make_pair(v.first+1,
            make_pair(v.second.first+x,v.second.second+y));
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
