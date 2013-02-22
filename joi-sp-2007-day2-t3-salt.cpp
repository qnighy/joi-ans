/*
 * Problem: joi-sp-2007-day2-t3-salt
 * Author: Masaki Hara
 * O(N^2)
 */
#include <algorithm>
#include <vector>
#include <cstdio>
#include "grader.h"
#include "salt.h"
using namespace std;

void play(int N, int E[][2]) {
  vector<int> deg(N+1);
  vector<char> V_alive(N+1, 1);
  vector<char> E_alive(N-1, 1);
  int V_size = N;
  int E_size = N-1;
  for(int i = 0; i < N-1; i++) {
    deg[E[i][0]]++;
    deg[E[i][1]]++;
  }
  while(true) {
    int u,v;
    if(V_size&1) {
      for(v = 1; v <= N; v++)
        if(V_alive[v] && (deg[v]^E_size^1)&1) break;
      u=v;
      V_alive[v] = false;
      V_size--;
      for(int i = 0; i < N-1; i++) {
        if(E_alive[i] && (E[i][0]==v || E[i][1]==v)) {
          E_alive[i] = false;
          deg[E[i][0]]--;
          deg[E[i][1]]--;
          E_size--;
        }
      }
    } else {
      int eid;
      for(eid = 0; eid < N-1; eid++)
        if(E_alive[eid]) break;
      E_alive[eid] = false;
      deg[E[eid][0]]--;
      deg[E[eid][1]]--;
      u=E[eid][0];
      v=E[eid][1];
      E_size--;
    }
    int ru,rv;
    turn(u,v,&ru,&rv);
    if(ru==rv) {
      V_alive[rv] = false;
      V_size--;
      for(int i = 0; i < N-1; i++) {
        if(E_alive[i] && (E[i][0]==rv || E[i][1]==rv)) {
          E_alive[i] = false;
          deg[E[i][0]]--;
          deg[E[i][1]]--;
          E_size--;
        }
      }
    } else if(ru<rv) {
      int eid;
      for(eid = 0; eid < N-1; eid++)
        if(E_alive[eid] && E[eid][0]==ru && E[eid][1]==rv) break;
      E_alive[eid] = false;
      deg[E[eid][0]]--;
      deg[E[eid][1]]--;
      E_size--;
    }
  }
}
