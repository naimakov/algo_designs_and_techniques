#include <ctime>
#include <iostream>

using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Least Common Multiple
 * Given two integers a and b, find their least common multiple.
 * Input: integer a and b given in the same line separated by space.
 * Output: LCM(a,b)
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

long long lcm_naive(unsigned int a, unsigned int b) {
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}
unsigned int gcd_fast(unsigned int a, unsigned int b) {
  if (b == 0)
    return a;
  unsigned int a_tmp = a % b;
  return gcd_fast(b, a_tmp);
}
long long lcm_fast(unsigned int a, unsigned int b) {
  if (a == 0 || b == 0)
    return 0;
  unsigned int gcd = gcd_fast(a, b);
  a /= gcd;
  return (long long)a * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  tic();
  std::cout << lcm_fast(a, b) << std::endl;
  toc();
  return 0;
}
