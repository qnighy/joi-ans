/*
 * Problem: joi-sp-2007-day4-t2-lines
 * Author: Masaki Hara
 * O(N^2 log N)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

struct Rat {
  int num,den;
  Rat() : num(0),den(1) {}
  Rat(int num, int den) :
    num(den>0 ? num : -num), den(den>0 ? den : -den) {}
  bool operator<(const Rat& o) const {
    return (long long)num*o.den < (long long)o.num*den;
  }
  bool operator==(const Rat& o) const {
    return (long long)num*o.den == (long long)o.num*den;
  }
};

int main() {
  int N; scanf("%d", &N);
  static int a[1000],b[1000],c[1000],d[1000];
  for(int i = 0; i < N; i++) {
    scanf("%d%d%d%d", a+i, b+i, c+i, d+i);
  }
  int count = 1;
  static bool conflict[1000];
  for(int i = 0; i < N; i++) {
    conflict[i] = false;
    static Rat pts[1000];
    int pts_size = 0;
    for(int j = 0; j < i; j++) {
      if(conflict[j]) continue;
      int px =        a[i], py =        b[i];
      int qx = c[i] - a[i], qy = d[i] - b[i];
      int rx =        a[j], ry =        b[j];
      int sx = c[j] - a[j], sy = d[j] - b[j];
      // equation: p + kq = r + ls
      // cross(p+kq, s) = cross(r+ls,s)
      // cross(p,s) + k*cross(q,s) = cross(r,s)
      int num = (rx-px) * sy - (ry-py) * sx;
      int den = qx * sy - qy * sx;
      if(den) {
        pts[pts_size++] = Rat(num,den);
      } else if(num) {
        continue;
      } else {
        conflict[i] = true;
        break;
      }
    }
    if(conflict[i]) continue;
    sort(pts,pts+pts_size);
    count += 1 + (unique(pts,pts+pts_size)-pts);
  }
  printf("%d\n", count);
  return 0;
}

