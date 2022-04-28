#include <ctime>
#include <iostream>

using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Last digit of a Large Fibonacci Number
 * Given an integer n, find the last digit of the nth Fibonacci number.
 * Input: integer n
 * Output: last digit of F_n
 * Constraints: 0<=n<=10^7
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

unsigned long long get_fibonacci_last_digit_naive(unsigned long long n) {
  if (n <= 1)
    return n;

  unsigned long long previous = 0;
  unsigned long long current = 1;

  for (unsigned long long i = 0; i < n - 1; ++i) {
    unsigned long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % 10;
}
unsigned long long get_fibonacci_last_digit_fast(unsigned long long n) {
  if (n <= 1)
    return n;

  unsigned long long previous = 0;
  unsigned long long current = 1;

  for (unsigned long long i = 0; i < n - 1; ++i) {
    unsigned long long tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current) % 10;
  }

  return current;
}

int main() {
  unsigned long long n;
  std::cin >> n;
  tic();
  unsigned long long c = get_fibonacci_last_digit_fast(n);
  std::cout << c << '\n';
  toc();
}
