#include <iostream>

using namespace std;

int N,M;

const int MAX_M = 100;
const int MAX_N = 100;

char grand[MAX_N][MAX_M];

// (x,y)の座標について調査する
void dfs(int x, int y) {
  grand[x][y] = '.';
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x + dx, ny = y + dy;
      if (nx >= 0 && nx < N && ny >= 0 && ny < M && grand[nx][ny] == 'W') {
        dfs(nx,ny);
      }
    }
  }
  return ;
}

void slove() {
  int counter = 0;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      if (grand[i][j] == 'W') {
        dfs(i,j);
        counter++ ;
      }
    }
  }
  // std::cout << "here" << '\n';
  std::cout << counter << '\n';

  return ;
}

int main(int argc, char const *argv[]) {

  std::cin >> N >> M;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      std::cin >> grand[i][j];
    }
  }

  slove();
  return 0;
}
