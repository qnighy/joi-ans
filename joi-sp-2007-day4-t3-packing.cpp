/*
 * Problem: joi-sp-2007-day4-t3-packing
 * Author: Masaki Hara
 * Physical simulation & simple simulated annealing
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int R = 100000000;
const double ratio_init = 0.9999;
const double ratio_ratio = 1.0000001;

int main(int argc, char **argv) {
  if(argc<2) {
    fprintf(stderr, "usage: %s <filename_base> [<seed>]\n", argv[0]);
    return 1;
  }
  const char *filename_base = argv[1];
  int seed = 2012;
  if(argc>=3) sscanf(argv[2], "%d", &seed);
  srand(seed);

  int N; scanf("%d", &N);
  double best_score=0.0;
  double ratio = pow(ratio_init, 1.0/sqrt(N));
  for(int try_i = 0; ; try_i++) {
    static int x[100],y[100];
    for(int i = 0; i < N; i++) {
      x[i] = rand()%R;
      y[i] = rand()%R;
    }
    double temper = 0.1;
    while(temper > 0.1/R) {
      const int v = rand()%N;
      pair<double,pair<double,double> > mv(R*2,make_pair(0,0));
      mv = min(mv,make_pair(    x[v]*(1.0/R),make_pair(temper,0.0)));
      mv = min(mv,make_pair(    y[v]*(1.0/R),make_pair(0.0,temper)));
      mv = min(mv,make_pair(1.0-x[v]*(1.0/R),make_pair(-temper,0.0)));
      mv = min(mv,make_pair(1.0-y[v]*(1.0/R),make_pair(0.0,-temper)));
      for(int i = 0; i < N; i++) {
        if(i==v) continue;
        double dx = (x[v]-x[i])*(1.0/R);
        double dy = (y[v]-y[i])*(1.0/R);
        double len = hypot(dx,dy);
        if(len > 0.0) {
          mv = min(mv,make_pair(len*0.5,make_pair(
                  temper/len*dx,
                  temper/len*dy)));
        }
      }
      x[v] += (int)(mv.second.first * R);
      y[v] += (int)(mv.second.second * R);
      x[v] += (int)((0.1*rand()/RAND_MAX-0.05) * temper * R);
      y[v] += (int)((0.1*rand()/RAND_MAX-0.05) * temper * R);
      x[v] = max(0, min(R, x[v]));
      y[v] = max(0, min(R, y[v]));
      temper *= ratio;
    }
    double score = 1.0;
    for(int i = 0; i < N; i++) {
      score = min(score, x[i] * 0.00000001);
      score = min(score, y[i] * 0.00000001);
      score = min(score, (100000000 - x[i]) * 0.00000001);
      score = min(score, (100000000 - y[i]) * 0.00000001);
    }
    for(int i = 0; i < N; i++) {
      for(int j = i+1; j < N; j++) {
        double dx = x[i]-x[j];
        double dy = y[i]-y[j];
        double len = hypot(dx,dy) * 0.000000005;
        score = min(score, len);
      }
    }
    if(score > best_score) {
      static char fname[1000];
      snprintf(fname, 1000, "%s-%.08f.txt", filename_base, score);
      FILE *out = fopen(fname, "w");
      for(int i = 0; i < N; i++) {
        fprintf(out, "%d %d\n", x[i], y[i]);
      }
      fclose(out);
      best_score = score;
    }
    fprintf(stderr, "%d: best: %.08f / score: %.08f / ratio: %.08f\n", try_i, best_score, score, ratio);
    ratio *= ratio_ratio;
  }
  return 0;
}

