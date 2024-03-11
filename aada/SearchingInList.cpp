#include "bits/stdc++.h"
using namespace std;

int linearSearch(const vector<int> &nums, int target) {
  int n = size(nums);
  for (int i = 0; i < n; i++) {
    if (nums[i] == target)
      return i;
  }

  return -1;
}

int binarySearch(const vector<int> &nums, int target) {
  function<int(int, int)> search = [&](int L, int R) {
    if (L > R)
      return -1;

    int mid = (L + R) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target)
      return search(L, mid - 1);

    return search(mid + 1, R);
  };

  int n = size(nums);
  return search(0, n - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> nums{1, 4, 7, 7, 8, 9, 18, 27, 31, 56, 81};
  vector<int> elements_to_search{1, 81, 7, 3};

  cout << "Linear Search:\n";
  for (auto x : elements_to_search) {
    int id = linearSearch(nums, x);
    if (id != -1)
      cout << "Element " << x << " found at index: " << id << "\n";
    else
      cout << x << " is not present in nums.\n";
  }

  cout << "\nBinary Search:\n";
  for (auto x : elements_to_search) {
    int id = binarySearch(nums, x);
    if (id != -1)
      cout << "Element " << x << " found at index: " << id << "\n";
    else
      cout << x << " is not present in nums.\n";
  }

  return 0;
}
