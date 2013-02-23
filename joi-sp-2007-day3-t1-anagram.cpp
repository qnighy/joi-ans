/*
 * Problem: joi-sp-2007-day3-t1-anagram
 * Author: Masaki Hara
 * O(NC)
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  char s[30]; scanf("%s", s);
  int N = strlen(s);
  int h[26]; fill(h, h+26, 0);
  long long count = 0;
  long long factor = 1;
  for(int i = N-1; i >= 0; i--) {
    int cur = s[i]-'A';
    factor = factor * (N-i) / ++h[cur];
    for(int c = 0; c < cur; c++) {
      if(h[c]) {
        count += factor * h[c] / (N-i);
      }
    }
  }
  printf("%lld\n", count+1);
  return 0;
}
