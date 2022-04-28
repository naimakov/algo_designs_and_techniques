#include <assert.h>

#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

time_t t_start, t_end;

/**
 * Maximizing Value of the Loot
 * Implement an algorithm for the fractional knapsack problem.
 * Input:
 *      integers n, W, v_i, w_i - number of items, capacity,
 *      values and weights of items.
 * Output:
 *      max value of fractions of items that fit into knapsack.
 * Constraints:
 *      1<=n<=10^3, 0<=W<=2*10^6, 0<=v_i<=2*10^6, 0<w_i<=2*10^6
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

void insertion_sort(double *p, int *index, int n) {
  int i = 1, j, k;
  double x;
  while (i < n) {
    x = p[i];
    k = i;
    j = i - 1;
    while (j >= 0 && p[j] < x) {
      p[j + 1] = p[j];
      index[j + 1] = index[j];
      j = j - 1;
    }
    p[j + 1] = x;
    index[j + 1] = k;
    i++;
  }
  return;
}

double get_optimal_value(int capacity, vector<int> weights,
                         vector<int> values) {
  int n = weights.size();
  double value = 0.0;

  if (capacity == 0) return value;

  int index[n];
  double max_vpi[n];
  for (int i = 0; i < n; i++) {
    max_vpi[i] = (double)values[i] / weights[i];
    index[i] = i;
  }

  insertion_sort(max_vpi, index, n);

  for (int i = 0; i < n; i++) {
    if (capacity == 0) return value;
    int a = weights[index[i]] < capacity ? weights[index[i]] : capacity;
    value += a * max_vpi[i];
    capacity -= a;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  tic();
  double optimal_value = get_optimal_value(capacity, weights, values);
  toc();
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
