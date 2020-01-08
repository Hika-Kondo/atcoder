#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  long long onecouter = 0, zerocounter = 0;
  std::string number;
  std::cin >> number;
  int length = number.length();
  char idx = '0';
  for (long long  i = 0; i < length; i++) {

    if (number[i] == idx) zerocounter++;
    if (idx == '0') idx = '1';
    else idx = '0';
    if (number[i] == idx) onecouter++;
  }

  std::cout << min(zerocounter,onecouter) << '\n';

  return 0;
}
