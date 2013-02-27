/*
 * Problem: joi-sp-2008-day2-t3-belt
 * Author: Masaki Hara
 * O(N log N)
 */
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  int N; scanf("%d", &N);
  double D; scanf("%lf", &D);
  static int xs[1000],ys[1000];
  for(int i = 0; i < N; i++) {
    scanf("%d%d", xs+i, ys+i);
  }
  int max_cnt = 1;
  for(int v = 0; v < N; v++) {
    int cnt = 1;
    static pair<double,int> evts[4000];
    int evts_size = 0;
    for(int i = 0; i < N; i++) {
      if(i==v) continue;
      double x = xs[i]-xs[v];
      double y = ys[i]-ys[v];
      double center = atan2(y,x);
      double th1 = center-M_PI/2;
      double th2 = center+M_PI/2;
      if(th1 < -M_PI) th1 += M_PI*2;
      if(th2 >  M_PI) th2 -= M_PI*2;
      evts[evts_size++] = make_pair(th1,1);
      evts[evts_size++] = make_pair(th2,-1);
      pair<double,int> minevt = min(
          make_pair(th1,1),
          make_pair(th2,-1));
      double sqd = x*x+y*y-4*D*D;
      if(sqd>0) {
        double phi = atan2(sqrt(sqd), 2*D);
        double th3 = center-phi;
        double th4 = center+phi;
        if(th3 < -M_PI) th3 += M_PI*2;
        if(th4 >  M_PI) th4 -= M_PI*2;
        evts[evts_size++] = make_pair(th3,-1);
        evts[evts_size++] = make_pair(th4,1);
        minevt = min(minevt, min(
            make_pair(th3,-1),
            make_pair(th4,1)));
      }
      if(minevt.second==-1) cnt++;
    }
    sort(evts,evts+evts_size);
    for(int i = 0; i < evts_size; i++) {
      cnt += evts[i].second;
      max_cnt = max(max_cnt, cnt);
    }
  }
  printf("%d\n", max_cnt);
  return 0;
}
