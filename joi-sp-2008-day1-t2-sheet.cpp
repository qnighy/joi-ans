/*
 * Problem: joi-sp-2008-day1-t2-sheet
 * Author: Masaki Hara
 * O(NWH + N^2)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, W, H, tbl[100][100];
bool vis[1000];
int st[1000], st_size;

void dfs(int v) {
  vis[v]=true;
  int bb1=H,bb2=W,bb3=0,bb4=0;
  for(int y = 0; y < H; y++) {
    for(int x = 0; x < W; x++) {
      if(tbl[y][x]==v) {
        bb1=min(bb1,y  ); bb2=min(bb2,x  );
        bb3=max(bb3,y+1); bb4=max(bb4,x+1);
      }
    }
  }
  for(int y = bb1; y < bb3; y++) {
    for(int x = bb2; x < bb4; x++) {
      if(tbl[y][x]>=0 && !vis[tbl[y][x]]) {
        dfs(tbl[y][x]);
      }
    }
  }
  st[st_size++] = v;
}

int main() {
  scanf("%d%d%d", &N, &W, &H);
  for(int y = 0; y < H; y++) {
    for(int x = 0; x < W; x++) {
      scanf("%d", &tbl[y][x]); tbl[y][x]--;
    }
  }
  fill(vis,vis+N, false);
  st_size = 0;
  for(int v = 0; v < N; v++) {
    if(!vis[v]) dfs(v);
  }
  for(int i = N-1; i >= 0; i--) {
    printf("%d%c", st[i]+1, " \n"[i==0]);
  }
  return 0;
}
