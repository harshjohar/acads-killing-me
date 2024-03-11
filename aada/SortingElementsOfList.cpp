#include "bits/stdc++.h"
using namespace std;

vector<int> selectionSort(vector<int> nums) {
  int comparison = 0, swaps = 0;
  auto findMin = [&](int L, int R) {
    int min_id = L;
    for (int i = L + 1; i <= R; i++) {
      comparison++;
      if (nums[min_id] > nums[i])
        min_id = i;
    }

    return min_id;
  };

  int n = size(nums);

  for (int i = 0; i < n; i++) {
    int id = findMin(i, n - 1);
    swap(nums[i], nums[id]);
    swaps++;
  }

  cout << "Selection Sort:\n";
  cout << "Swaps: " << swaps << "\n";
  cout << "Comparisons: " << comparison << "\n\n";

  return nums;
}

vector<int> bubbleSort(vector<int> nums) {
  int comparison = 0, swaps = 0;
  int n = size(nums);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j + 1 < n - i; j++) {
      comparison++;
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
        swaps++;
      }
    }
  }

  cout << "Bubble Sort:\n";
  cout << "Swaps: " << swaps << "\n";
  cout << "Comparisons: " << comparison << "\n\n";
  return nums;
}

/**
 * Sorts array using insertion sort algorithm
 * Time Complexity: O(n^2)
 */
vector<int> insertionSort(vector<int> nums) {
  int comparison = 0, swaps = 0;
  int n = size(nums);

  for (int i = 1; i < n; i++) {
    int j = i;
    while (j - 1 >= 0 and nums[j - 1] > nums[j]) {
      comparison++;
      swaps++;
      swap(nums[j - 1], nums[j]);
    }

    comparison++; // comparison when condition for while is false.
  }

  cout << "Insertion Sort:\n";
  cout << "Swaps: " << swaps << "\n";
  cout << "Comparisons: " << comparison << "\n\n";
  return nums;
}

/**
 * Merge two sorted list
 * Time Complexity: O(n + m)
 */
vector<int> merge(vector<int> &a, vector<int> &b) {
  int n = size(a);
  int m = size(b);

  vector<int> c(n + m);

  // pa, pb are pointer to array a and b current element
  for (int i = 0, pa = 0, pb = 0; i < n + m; i++) {
    if (pa >= n)
      c[i] = b[pb++];
    else if (pb >= m)
      c[i] = a[pa]++;
    else {
      if (a[pa] < b[pb])
        c[i] = a[pa++];
      else
        c[i] = b[pb++];
    }
  }

  return c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> nums{18, 56, 27, 7, 8, 4, 9, 31, 81, 1};

  selectionSort(nums);
  bubbleSort(nums);
  insertionSort(nums);

  vector<int> a{7, 8, 18, 27, 56};
  vector<int> b{1, 4, 9, 31, 81};
  auto sortedMergedList = merge(a, b);

  int sz = size(sortedMergedList);
  for (int i = 0; i < sz; i++)
    cout << sortedMergedList[i] << " \n"[i == sz - 1];

  return 0;
}
