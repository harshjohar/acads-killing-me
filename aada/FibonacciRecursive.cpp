#include "bits/stdc++.h"
using namespace std;

int fib_recursive(int n) {
  if (n <= 1)
    return n;
  return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_optimised(int n) {
  int a = 0, b = 1;
  while (n--) {
    int c = a + b;
    a = b;
    b = c;
  }

  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i <= 10; i++)
    cout << fib_optimised(i) << " \n"[i == 10];

  return 0;
}
