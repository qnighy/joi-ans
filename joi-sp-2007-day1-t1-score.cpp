/*
 * Problem: joi-sp-2007-day1-t1-score
 * Author: Masaki Hara
 * O(N+100)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int N; scanf("%d", &N);
  static int score[100000];
  for(int i = 0; i < N; i++) {
    scanf("%d", score+i);
  }
  static int histogram[101];
  fill(histogram, histogram+101, 0);
  for(int i = 0; i < N; i++) {
    histogram[score[i]]++;
  }
  for(int i = 1; i <= 100; i++) {
    histogram[i] += histogram[i-1];
  }
  for(int i = 0; i < N; i++) {
    printf("%d\n", histogram[100]-histogram[score[i]]+1);
  }
  return 0;
}
