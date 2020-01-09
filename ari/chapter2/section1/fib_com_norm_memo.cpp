#include <iostream>   //標準入出力を使うときに必要なheaderファイル
#include <iomanip>    //とりあえずおまじないと考えても良い．
#include <time.h>

using namespace std;

int fib(int n) {
  if (n <= 1) return n;
  return fib(n-1) + fib(n-2);
}

const int MAX_N = 100;

int MeMo[MAX_N];

int fastfib(int n) {
  if (n<=1) return n;
  if (MeMo[n] != 0) return MeMo[n];
  return MeMo[n] = fastfib(n-1) + fastfib(n-2);
}

int main(int argc, char const *argv[]) {
  clock_t start = clock();
  std::cout << fib(40) << '\n';
  clock_t end = clock();
  std::cout << end - start << '\n';
  clock_t start_ = clock();
  std::cout << fastfib(40) << '\n';
  clock_t end_ = clock();
  std::cout << end_ - start_ << '\n';
  return 0;
}
