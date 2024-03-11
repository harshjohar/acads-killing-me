#include "bits/stdc++.h"
using namespace std;

using i64 = long long;

vector<int> quickSort(vector<int> nums) {
  auto start = clock();

  auto partition = [&](int L, int R) {
    if (L == R)
      return L;

    int id = R;
    swap(nums[id], nums[R]);

    int pivot = nums[R];
    int i = L, last_small = L - 1;
    while (i < R) {
      if (nums[i] <= pivot) {
        swap(nums[i], nums[last_small + 1]);
        last_small++;
      }

      i++;
    }

    swap(nums[R], nums[last_small + 1]);
    return last_small + 1;
  };

  function<void(int, int)> sort = [&](int L, int R) {
    if (L >= R)
      return;

    int pivot_id = partition(L, R);
    sort(L, pivot_id - 1);
    sort(pivot_id + 1, R);
  };

  int n = size(nums);
  sort(0, n - 1);

  auto end = clock();
  cout << "Time elapsed: " << 1000. * (end - start) / CLOCKS_PER_SEC
       << " ms.\n\n";

  return nums;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T = int> T get_rand(T l, T r) {
  assert(l <= r);
  return uniform_int_distribution<T>(l, r)(rng);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 5000;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    a[i] = get_rand(-10000, 10000);

  // quicksort on random array
  quickSort(a);

  // quicksort on sorted array
  sort(begin(a), end(a));
  quickSort(a);

  // quicksort on reverse sorted array
  reverse(begin(a), end(a));
  quickSort(a);

  return 0;
}
