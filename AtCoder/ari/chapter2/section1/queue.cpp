#include <queue>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
  queue<int> que; //スタックと異なるところはpopで下から取り出す
  que.push(1);
  que.push(2);
  que.push(3);
  printf("%d\n", que.front()); //一番下の要素を確認
  que.pop();
  printf("%d\n", que.front()); //一番下の要素を確認
  que.pop();
  printf("%d\n", que.front()); //一番下の要素を確認
  que.pop();
  return 0;
}
