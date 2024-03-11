#include "bits/stdc++.h"
using namespace std;

constexpr int inf = 1e9;

int findMin(vector<int> &nums) {
  function<int(int, int)> f = [&](int L, int R) {
    if (L > R)
      return inf;

    int mid = (L + R) / 2;
    return min({nums[mid], f(L, mid - 1), f(mid + 1, R)});
  };

  int n = size(nums);
  return f(0, n - 1);
}

int findMax(vector<int> &nums) {
  function<int(int, int)> f = [&](int L, int R) {
    if (L > R)
      return -inf;

    int mid = (L + R) / 2;
    return max({nums[mid], f(L, mid - 1), f(mid + 1, R)});
  };

  int n = size(nums);
  return f(0, n - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector a{1, 5, 3, 0, 10, -1, 9};
  cout << findMin(a) << " " << findMax(a) << "\n";

  return 0;
}
