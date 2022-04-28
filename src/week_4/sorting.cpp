#include <algorithm>
#include <assert.h>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using std::cin;
using std::cout;
using std::swap;
using std::vector;

time_t t_start, t_end;

/**
 * Improving Quick Sort
 * Redesign a given implementation of randomized quick sort algo
 * for sequences with many equal elements
 *
 * Input:
 *      1st line - integer n
 *      2nd line - a_0, a_1, ... , a_{n-1}
 * Output:
 *      the sequence sorted in non-decreasing order
 * Constraints:
 *      1 <= n <= 10^5, 1 <= a_i <= 10^9 for 0 <= i < n
 * Time limit: 1 sec
 * Memory limit: 512 mb
 */
void tic(int mode = 0) {
  if (mode == 0)
    t_start = time(0);
  else {
    t_end = time(0);
    cout << "Elapsed time is " << difftime(t_end, t_start) << " seconds\n";
  }
}
void toc() { tic(1); }

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int> &a, int l, int r, int &m1, int &m2) {
  int x = a[l];
  int j1 = l, j2 = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j2++;
      swap(a[i], a[j2]);
    }
  }
  swap(a[l], a[j2]);
  for (int i = j2 - 1; i >= l; i--) {
    if (a[i] < x) {
      j1 = i + 1;
      break;
    }
  }
  m1 = j1;
  m2 = j2;
  return;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m1 = 0, m2 = 0;
  partition3(a, l, r, m1, m2);

  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

void randomized_quick_sort_fast(vector<int> &a, int l, int r) {
  while (l < r) {
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m1 = 0, m2 = 0;
    partition3(a, l, r, m1, m2);
    if (m1 - l < r - m2) {
      randomized_quick_sort_fast(a, l, m1 - 1);
      l = m2 + 1;
    } else {
      randomized_quick_sort_fast(a, m2 + 1, r);
      r = m1 - 1;
    }
  }
  return;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  b = a;
  randomized_quick_sort(a, 0, a.size() - 1);
  randomized_quick_sort_fast(b, 0, b.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
  for (size_t i = 0; i < b.size(); ++i) {
    std::cout << b[i] << ' ';
  }
}
