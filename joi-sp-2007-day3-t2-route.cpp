/*
 * Problem: joi-sp-2007-day3-t2-route
 * Author: Masaki Hara
 * O(MN log MN)
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
  int N,M; scanf("%d%d", &N, &M);
  static int x[100],y[100];
  for(int i = 0; i < N; i++) {
    scanf("%d%d", x+i, y+i);
  }
  static int from[10000],to[10000],cost[10000];
  vector<vector<int> > graph(N);
  for(int i = 0; i < M; i++) {
    int a,b,c; scanf("%d%d%d", &a, &b, &c); a--; b--;
    from[i*2+0] = a; to[i*2+0] = b; cost[i*2+0]=c; graph[a].push_back(i*2+0);
    from[i*2+1] = b; to[i*2+1] = a; cost[i*2+1]=c; graph[b].push_back(i*2+1);
  }
  priority_queue<pair<int,int> > pq;
  static int tim[10000]; fill(tim, tim+2*M, 150000000);
  for(int i = 0; i < (int)graph[0].size(); i++) {
    int e = graph[0][i];
    pq.push(make_pair(-cost[e],e));
  }
  while(!pq.empty()) {
    int e1 = pq.top().second;
    int t = -pq.top().first;
    pq.pop();
    if(t >= tim[e1]) continue;
    tim[e1] = t;
    int v = from[e1];
    int w = to[e1];
    for(int i = 0; i < (int)graph[w].size(); i++) {
      int e2 = graph[w][i];
      int u = to[e2];
      int dx1 = x[v] - x[w];
      int dy1 = y[v] - y[w];
      int dx2 = x[u] - x[w];
      int dy2 = y[u] - y[w];
      if(dx1*dx2+dy1*dy2 > 0) continue;
      if(t+cost[e2] < tim[e2]) {
        pq.push(make_pair(-t-cost[e2],e2));
      }
    }
  }
  int mincost = 150000000;
  for(int i = 0; i < (int)graph[1].size(); i++) {
    mincost = min(mincost, tim[graph[1][i]^1]);
  }
  printf("%d\n", mincost == 150000000 ? -1 : mincost);
  return 0;
}
