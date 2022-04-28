#include <assert.h>
#include <ctime>
#include <iostream>
#include <random>

using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Money Change
 * Given an integer m, find the minimum number of coins
 * needed to change m into coins of 1, 5 and 10.
 *
 * Input: an integer m
 * Output: minimum number of coins 1, 5, 10 that changes m.
 * Constraints: 1<=m<=10^3
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

int get_change(int m) {
  int count = 0;
  if (!m)
    return 0;
  count += m / 10;
  m %= 10;
  count += m / 5;
  m %= 5;
  count += m;
  return count;
}

int main() {
  assert(get_change(2) == 2);
  assert(get_change(28) == 6);
  assert(get_change(0) == 0);
  assert(get_change(1) == 1);
  assert(get_change(5) == 1);
  assert(get_change(10) == 1);

  std::cout << "All tests passed\n";

  int m;
  std::cin >> m;
  tic();
  std::cout << get_change(m) << '\n';
  toc();
}
