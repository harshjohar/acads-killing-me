#include "bits/stdc++.h"
using namespace std;

vector<int> mergeSort(vector<int> &nums) {
  auto merge = [&](int l1, int r1, int l2, int r2) {
    vector<int> a(begin(nums) + l1, begin(nums) + r1 + 1);
    vector<int> b(begin(nums) + l2, begin(nums) + r2 + 1);

    int n = size(a);
    int m = size(b);

    for (int i = l1, pa = 0, pb = 0; i < n + m + l1; i++) {
      if (pa >= n)
        nums[i] = b[pb++];
      else if (pb >= m)
        nums[i] = a[pa]++;
      else {
        if (a[pa] < b[pb])
          nums[i] = a[pa++];
        else
          nums[i] = b[pb++];
      }
    }
  };

  function<void(int, int)> sort = [&](int l, int r) {
    if (l >= r)
      return;

    int mid = (l + r) / 2;

    // sort two halves recursively
    sort(l, mid);
    sort(mid + 1, r);

    // merge the two sorted list into one
    merge(l, mid, mid + 1, r);
  };

  int n = size(nums);
  sort(0, n - 1);

  return nums;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> nums{18, 56, 27, 7, 8, 4, 9, 31, 81, 1};
  auto sortedList = mergeSort(nums);

  int n = size(sortedList);
  for (int i = 0; i < n; i++)
    cout << sortedList[i] << " \n"[i == n - 1];

  return 0;
}
