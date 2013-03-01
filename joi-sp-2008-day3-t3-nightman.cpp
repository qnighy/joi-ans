/*
 * Problem: joi-sp-2008-day3-t3-nightman
 * Author: Masaki Hara
 * O((A+B+C)^3)
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
using namespace std;

#define fhypot(x,y) (sqrt((x)*(x)+(y)*(y)))

const double EPS = 1e-9;

int main() {
  int A,B,C,W,H; scanf("%d%d%d%d%d", &A, &B, &C, &W, &H);
  static complex<double> pt[220];
  for(int i = 0; i < A; i++) {
    scanf("%lf%lf", &pt[i].real(), &pt[i].imag());
  }
  for(int i = 0; i < B; i++) {
    double x1,y1,x2,y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    pt[A+C+i*4+0] = complex<double>(x1,y1);
    pt[A+C+i*4+1] = complex<double>(x1,y2);
    pt[A+C+i*4+2] = complex<double>(x2,y1);
    pt[A+C+i*4+3] = complex<double>(x2,y2);
  }
  for(int i = 0; i < C; i++) {
    scanf("%lf%lf", &pt[A+i].real(), &pt[A+i].imag());
  }
  static double wf[220][220];
  for(int p0 = 0; p0 < A+B*4+C; p0++) {
    for(int p1 = 0; p1 < A+B*4+C; p1++) {
      bool ok = true;
      for(int i = 0; i < B; i++) {
        for(int p2 = A+C+i*4; p2 < A+C+i*4+4; p2++) {
          for(int p3 = A+C+i*4; p3 < A+C+i*4+4; p3++) {
            double d0 = ((pt[p0]-pt[p2])*conj(pt[p3]-pt[p2])).imag();
            double d1 = ((pt[p1]-pt[p2])*conj(pt[p3]-pt[p2])).imag();
            if(d0*d1>=-EPS) continue;
            double d2 = ((pt[p2]-pt[p0])*conj(pt[p1]-pt[p0])).imag();
            double d3 = ((pt[p3]-pt[p0])*conj(pt[p1]-pt[p0])).imag();
            if(d2*d3>=-EPS) continue;
            ok = false;
          }
        }
      }
      if(ok) {
        wf[p0][p1] = abs(pt[p0]-pt[p1]);
      } else {
        wf[p0][p1] = 1.0e100;
      }
    }
  }
  for(int k = 0; k < A+B*4+C; k++) {
    for(int i = 0; i < A+B*4+C; i++) {
      for(int j = 0; j < A+B*4+C; j++) {
        wf[i][j] = min(wf[i][j], wf[i][k]+wf[k][j]);
      }
    }
  }
  double sum = 0;
  for(int i = 0; i < C; i++) {
    double mv = 1.0e100;
    for(int j = 0; j < A; j++) {
      mv = min(mv, wf[A+i][j]);
    }
    sum += mv;
  }
  printf("%.03f\n", sum*2);
  return 0;
}
