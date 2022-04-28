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
 * Maximum Number of Prizes
 * Given an integer n, find the largest number of places k
 * so that \sum_{i=1}^k a_i, 0 < a_i != a_j for 1 <= i < j <= k.
 *
 * Input:
 *      integer n
 * Output:
 *      max number k such that n = \sum_{i=1}^k a_i,
 *      a_i \ne a_j, for 1 <= i < j <= k.
 * Constraints:
 *      1 <= n <= 10^9
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

vector<int> optimal_summands_naive(int n) {
  vector<int> summands;
  int i = 1;
  int flag;

  if (n <= 2) {
    summands.push_back(n);
    return summands;
  }
  while (n > 0) {
    flag = 1;
    for (size_t k = 0; k < summands.size(); k++) {
      if (summands[k] == n - i) {
        flag = 0;
        break;
      }
    }
    if (i == n - i) flag = 0;
    if (flag) {
      n -= i;
      summands.push_back(i);
    }
    i++;
  }
  return summands;
}
vector<int> optimal_summands_fast(int n) {
  vector<int> summands;
  int i = 1;
  int flag;

  if (n <= 2) {
    summands.push_back(n);
    return summands;
  }
  while (n > 0) {
    flag = 1;
    if (!summands.empty() && summands.back() >= n - i) flag = 0;
    if (i == n - i) flag = 0;
    if (n == i) flag = 1;
    if (flag) {
      n -= i;
      summands.push_back(i);
    }
    i++;
  }
  return summands;
}

void StressTest(int numIter, int range_n) {
  int n;
  std::uniform_int_distribution<int> rand_n(0, range_n);
  std::random_device rd;
  std::mt19937 re(rd());
  int i;
  for (i = 0; i < numIter; ++i) {
    n = rand_n(re);
    std::cout << "iteration #" << i << ": n=" << n << "\n";
    if (optimal_summands_naive(n) != optimal_summands_fast(n)) {
      std::cout << "Error: n= " << n << "\n";
      break;
    }
  }
  if (i == numIter) std::cout << "All tests passed!";
}

int main() {
  int n;
  std::cin >> n;
  tic();
  vector<int> summands = optimal_summands_fast(n);
  toc();
  std::cout << summands.size() << '\n';
  // for (size_t i = 0; i < summands.size(); ++i)
  //{
  //    std::cout << summands[i] << ' ';
  //}
  int nIter, range_n;
  std::cin >> nIter >> range_n;
  StressTest(nIter, range_n);
}
