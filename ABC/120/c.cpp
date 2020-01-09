#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  std::string s;
  std::cin >> s;
  long long counter = 0;
  stack<char> stack;
  for (auto i : s ) {
    if (stack.size() == 0) stack.push(i);
    else {
      if (stack.top() != i) {
        stack.pop();
        counter += 2;
      }
      else stack.push(i);
    }
  }
  std::cout << counter << '\n';


}
