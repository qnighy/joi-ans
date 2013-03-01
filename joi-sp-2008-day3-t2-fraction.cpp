/*
 * Problem: joi-sp-2008-day3-t2-fraction
 * Author: Masaki Hara
 * O(M+K)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int M,k; scanf("%d%d", &M, &k);
  static pair<int,int> st[200000]; int st_s = 0;
  st[st_s++] = make_pair(1,1);
  pair<int,int> cur = make_pair(0,1);
  while(k>0) {
    if(st_s==0) {
      break;
    } else if(st[st_s-1].second>M) {
      cur = st[st_s-2];
      st_s -= 2;
      k--;
    } else {
      st[st_s] = make_pair(
          cur.first  + st[st_s-1].first,
          cur.second + st[st_s-1].second);
      st_s++;
    }
  }
  if(st_s==0) {
    printf("-1\n");
  } else {
    printf("%d %d\n", cur.first, cur.second);
  }
  return 0;
}
