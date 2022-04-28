#include <ctime>
#include <iostream>
#include <random>

using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Last Digit of the Sum of Fibonacci Numbers
 * Given an integer n, find the last digit of \sum_{k=0}^n F_k
 * Input: integer n
 * Output: (\sum_{k=0}^n F_k ) % 10
 * Constraints: 0<=n<=10^14
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

int get_fibonacci_sum_naive(long long n) {
  if (n <= 1) return n;

  long long previous = 0;
  long long current = 1;
  long long sum = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current) % 10;
    sum += current;
    sum %= 10;
  }
  return sum;
}
int get_fibonacci_sum_fast(long long n) {
  if (n <= 1) return n;

  n = n % 60;
  if (n <= 1) return n;
  int previous = 0;
  int current = 1;

  for (long long i = 0; i < n - 1; ++i) {
    int tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current + 1) % 10;
  }
  return current;
}
void StressTest(int numIter) {
  long long n;
  std::uniform_int_distribution<long long> rand_n(0, 10e8);
  std::random_device rd;
  std::mt19937 re(rd());
  for (int i = 0; i < numIter; ++i) {
    n = rand_n(re);
    std::cout << "iteration #" << i << ": n=" << n << "\n";
    if (get_fibonacci_sum_naive(n) != get_fibonacci_sum_fast(n)) {
      std::cout << "Error: n= " << n << "\n";
      break;
    }
  }
  std::cout << "All tests passed!";
}
int main() {
  long long n = 0;
  std::cin >> n;
  tic();
  std::cout << get_fibonacci_sum_naive(n) << "\n";
  toc();
  int nIter;
  std::cin >> nIter;
  StressTest(nIter);
}
