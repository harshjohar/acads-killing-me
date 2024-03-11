#include "bits/stdc++.h"
using namespace std;

using i64 = long long;

vector<int> KMP(string text, string pattern) {
  int n = size(text), m = size(pattern);

  // build prefix function
  vector<int> pi(m);
  for (int i = 1; i < m; i++) {
    int j = pi[i - 1];
    while (j > 0 and pattern[i] != pattern[j])
      j = pi[j - 1];

    pi[i] = j + (pattern[i] == pattern[j]);
  }

  vector<int> matches;
  for (int i = 0, j = 0; i < n; i++) {
    while (j > 0 and text[i] != pattern[j])
      j = pi[j - 1];

    if (text[i] == pattern[j])
      j++;

    if (j == m) {
      matches.emplace_back(i - m);
      j = pi[j - 1];
    }
  }

  return matches;
}

constexpr int MOD = 1e9 + 7;
constexpr int BASE = 255;

// Calculates (a^b) % MOD
int power(int a, int b) {
  int ans = 1;
  for (; b; b /= 2, a = (1LL * a * a) % MOD) {
    if (b % 2)
      ans = (1LL * ans * a) % MOD;
  }

  return ans;
}
// Calculates modulo inverse of a w.r.t MOD
int inv(int a) { return power(a, MOD - 2); };

vector<int> RabinKarp(string text, string pattern) {
  vector<int> matches;
  int n = size(text);
  int m = size(pattern);
  if (m > n)
    return matches;

  int hash_pattern = 0, mul = 1;
  for (int i = 0; i < m; i++) {
    hash_pattern = (hash_pattern + mul * i64(pattern[i])) % MOD;
    mul = (1LL * mul * BASE) % MOD;
  }

  int hash_text = 0;
  mul = 1;
  for (int i = 0; i < m - 1; i++) {
    hash_text = (hash_text + mul * i64(text[i])) % MOD;
    mul = (1LL * mul * BASE) % MOD;
  }

  for (int i = m - 1; i < n; i++) {
    hash_text += (1LL * mul * text[i]) % MOD;
    if (hash_text == hash_pattern)
      matches.emplace_back(i - m + 1);

    hash_text -= text[i - m + 1];
    hash_text = (1LL * hash_text * inv(BASE)) % MOD;

    if (hash_text < 0)
      hash_text += MOD;
  }

  return matches;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string text, pattern;
  cin >> text >> pattern;

  // auto matches = KMP(text, pattern);
  // cout << size(matches) << " matches found!\n";
  // for (auto id : matches)
  //     cout << id << " ";

  auto matchesRabinKarp = RabinKarp(text, pattern);
  cout << size(matchesRabinKarp) << " matches found!\n";
  for (auto id : matchesRabinKarp)
    cout << id << " ";

  return 0;
}
