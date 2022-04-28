#include <assert.h>

#include <ctime>
#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::vector;

time_t t_start, t_end;

/**
 * Last Digit of the Partial Sum of Fibonacci Numbers
 * Given two integers m and n, find the last digit of \sum_{k=m}^n F_k
 * Input: integers m and n
 * Output: (\sum_{k=m}^n F_k ) % 10
 * Constraints: 0<=n<=m<=10^18
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

int get_fibonacci_partial_sum_naive(unsigned long long from,
                                    unsigned long long to) {
  int sum = 0;

  int current = 0;
  int next = 1;

  for (unsigned long long i = 0; i <= to; ++i) {
    if (i >= from) {
      sum += current;
      sum %= 10;
    }

    int new_current = next;
    next = (next + current) % 10;
    current = new_current;
  }

  return sum;
}

int get_nth_fibonacci_fast(int n) {
  if (n <= 1) return n;

  int previous = 0;
  int current = 1;

  for (int i = 0; i < n - 1; ++i) {
    int tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current) % 10;
  }
  return current;
}
int get_fibonacci_sum_fast(int n) {
  if (n <= 1) return n;
  int previous = 0;
  int current = 1;

  for (int i = 0; i < n - 1; ++i) {
    int tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current + 1) % 10;
  }
  return current;
}

int get_fibonacci_partial_sum_fast(unsigned long long m, unsigned long long n) {
  int n_mod_60 = n % 60;
  int m_minus_1_mod_60 = (m - 1) % 60;
  if (m != 0) {
    if (n != m) {
      int gn = get_fibonacci_sum_fast(n_mod_60);
      int gm = get_fibonacci_sum_fast(m_minus_1_mod_60);
      return gn >= gm ? gn - gm : 10 + (gn - gm);
    } else {
      return get_nth_fibonacci_fast(n_mod_60);
    }
  } else {
    return get_fibonacci_sum_fast(n_mod_60);
  }
}
void StressTest(int numIter, unsigned long long range_n) {
  unsigned long long n, m;
  std::uniform_int_distribution<unsigned long long> rand_n(0, range_n);
  std::random_device rd;
  std::mt19937 re(rd());
  int i;
  for (i = 0; i < numIter; ++i) {
    n = rand_n(re);
    std::uniform_int_distribution<unsigned long long> rand_m(0, n);
    m = rand_m(re);
    std::cout << "iteration #" << i << ": n=" << n << ", m=" << m << "\n";
    if (get_fibonacci_partial_sum_naive(m, n) !=
        get_fibonacci_partial_sum_fast(m, n)) {
      std::cout << "Error: n= " << n << ", m=" << m << "\n";
      break;
    }
  }
  if (i == numIter) std::cout << "All tests passed!";
}
int main() {
  /*
  unsigned long long from, to;
  unsigned long long k_long = 10e7;
  unsigned long long k_mod_60 = k_long % 60;
  int k_mod_60_short = k_mod_60;

  assert(get_fibonacci_partial_sum_fast(0,0) == 0);
  assert(get_fibonacci_partial_sum_fast(0,1) == 1);
  assert(get_fibonacci_partial_sum_fast(1,6) == 0);
  assert(get_fibonacci_partial_sum_fast(5,6) == 3);
  assert(get_fibonacci_partial_sum_fast(1,2) == 2);
  assert(get_fibonacci_partial_sum_fast(3,7) == 1);
  assert(get_fibonacci_partial_sum_fast(10,10) == 5);
  assert(get_fibonacci_partial_sum_fast(10,200) == 2);
  assert(get_fibonacci_partial_sum_fast(0,k_long) ==
  get_fibonacci_sum_fast(k_mod_60_short));

  std::cout << "All tests passed\n";

  std::cin >> from >> to;
  tic();
  std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
  toc();
  */
  int nIter;
  unsigned long long range_n;
  std::cin >> nIter >> range_n;
  StressTest(nIter, range_n);
}
