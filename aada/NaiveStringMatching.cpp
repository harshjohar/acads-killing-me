#include "bits/stdc++.h"
using namespace std;

bool naivePatternMatching(string text, string pattern) {
  int n = size(text);
  int m = size(pattern);

  for (int i = 0; i + m < n; i++) {
    for (int j = 0; j <= m; j++) {
      if (j == m)
        return true;

      if (text[i + j] != pattern[j])
        break;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string text = "patpatrandomwordpatternpatpatbigdata";
  string pattern = "pattern";

  cout << naivePatternMatching(text, pattern);

  return 0;
}
