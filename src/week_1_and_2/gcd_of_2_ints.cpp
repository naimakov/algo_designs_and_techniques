#include <ctime>
#include <iostream>

using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Greatest Common Divisor
 * Given two integers a and b, find their greatest common divisor.
 * Input: integer a and b given in the same line separated by space.
 * Output: GCD(a,b)
 * Constraints: 1<=a,b<=2*10^9
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

unsigned int gcd_naive(unsigned int a, unsigned int b) {
  unsigned int current_gcd = 0;
  for (unsigned int d = 1; d <= a + b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
unsigned int gcd_fast(unsigned int a, unsigned int b) {
  if (b == 0)
    return a;
  unsigned int a_tmp = a % b;
  return gcd_fast(b, a_tmp);
}

int main() {
  unsigned int a, b;
  std::cin >> a >> b;
  tic();
  std::cout << gcd_fast(a, b) << std::endl;
  toc();
  return 0;
}