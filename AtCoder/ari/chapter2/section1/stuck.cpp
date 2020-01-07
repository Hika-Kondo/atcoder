#include <stack>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
  stack<int> s; //スタックの宣言
  //スタックとは上にデータを積むpushメソッドと上からデータを取るpopメソッドがある
  s.push(1);
  s.push(2);
  s.push(3);
  printf("%d\n", s.top()); //一番上の要素を確認
  s.pop(); //一番上の要素を取る
  printf("%d\n", s.top()); //一番上の要素を確認
  s.pop();
  printf("%d\n", s.top()); //一番上の要素を確認
  s.pop(); //スタックは空

  return 0;
}
