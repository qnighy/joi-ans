/*
 * Problem: joi-sp-2007-day3-t3-circuit
 * Author: Masaki Hara
 * O(N log^2 K)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int x, int y) {
  while(y) {
    int t = x%y; x = y; y = t;
  }
  return x;
}

// gcd(pow(x, Infinity), y)
int gcdInf(int x, int y) {
  int z = 1;
  while(true) {
    int g = gcd(x,y);
    if(g == 1) break;
    z *= g; y /= g;
  }
  return z;
}

int main() {
  int N,K; scanf("%d%d", &N, &K);
  static int a[10000];
  for(int i = 0; i < N; i++) {
    scanf("%d", a+i); a[i]--;
  }
  static bool vis[10000];
  fill(vis,vis+N, false);
  static pair<int,int> l[10000];
  int l_size = 0;
  for(int i = 0; i < N; i++) {
    if(vis[i]) continue;
    int s = 0;
    for(int j = i; !vis[j]; j=a[j]) {
      vis[j] = true;
      s++;
    }
    l[l_size++] = make_pair(s,i);
  }
  sort(l, l+l_size);
  static int b[10000];
  for(int i = 0; i < l_size;) {
    int s = l[i].first;
    int dup = gcdInf(s,K);
    if(i+dup>l_size || l[i+dup-1].first != s) {
      printf("%d\n", 0);
      return 0;
    }
    static int loo[10000];
    for(int j = 0; j < dup; j++) {
      int k = j;
      int x = l[i+j].second;
      do {
        loo[k] = x;
        x = a[x];
        k = (k+K)%(s*dup);
      } while(x != l[i+j].second);
    }
    for(int j = 0; j < s*dup; j++) {
      b[loo[j]] = loo[(j+1)%(s*dup)];
    }
    i += dup;
  }
  for(int i = 0; i < N; i++) {
    printf("%d\n", b[i]+1);
  }
  return 0;
}

