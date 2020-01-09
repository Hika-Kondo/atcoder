#include <iostream>   //標準入出力を使うときに必要なheaderファイル
#include <iomanip>    //とりあえずおまじないと考えても良い．
#include <time.h>
#include <queue>
#include <cstdio>

using namespace std;

char maze[100][100];
int N,M;
int gx,gy;
int sx,sy;

int d[100][100];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
  queue<P> que;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      d[i][j] = INF;
    }
  }
  que.push(P(sx,sy));
  d[sx][sy] = 0;

  while (que.size()) {
    P p = que.front(); que.pop();

    if (p.first == gx && p.second == gy) break;

    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i] , ny = p.second + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M && )
    }
  }
}
