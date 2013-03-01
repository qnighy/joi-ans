/*
 * Problem: joi-sp-2008-day3-t1-origami
 * Author: Masaki Hara
 * O(N log N + 20N)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int N,W,H; scanf("%d%d%d", &N, &W, &H);
  static int xd[10000];
  static pair<pair<int,int>,pair<int,int> > evt[10000];
  for(int i = 0; i < N; i++) {
    int x1,y1,x2,y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2); x1--; y1--;
    xd[i*2+0] = x1;
    xd[i*2+1] = x2;
    evt[i*2+0] = make_pair(make_pair(y1, 1),make_pair(x1,x2));
    evt[i*2+1] = make_pair(make_pair(y2,-1),make_pair(x1,x2));
  }
  sort(xd,xd+2*N); int xds = unique(xd,xd+2*N)-xd;
  sort(evt, evt+2*N);
  static int cnt[10000]; fill(cnt, cnt+xds, 0);
  static int last[10000]; fill(last, last+xds, 0);
  int maxcnt = 1;
  int area = 0;
  for(int i = 0; i < N*2; i++) {
    int x1c = lower_bound(xd,xd+xds,evt[i].second.first )-xd;
    int x2c = lower_bound(xd,xd+xds,evt[i].second.second)-xd;
    for(int x = x1c; x < x2c; x++) {
      if(maxcnt < cnt[x]) {
        maxcnt = cnt[x];
        area = 0;
      }
      if(maxcnt == cnt[x]) {
        area += (xd[x+1]-xd[x])*(evt[i].first.first-last[x]);
      }
      last[x] = evt[i].first.first;
      cnt[x] += evt[i].first.second;
    }
  }
  printf("%d\n%d\n", maxcnt, area);
  return 0;
}
