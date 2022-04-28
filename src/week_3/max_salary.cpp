#include <assert.h>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

time_t t_start, t_end;

/**
 * Maximum Salary
 * Given several integer numbers, find the largest number
 * from these numbers.
 *
 * Input:
 *      integer n, a_i, i=1,...,n
 * Output:
 *      the largest number composed out of a_i, i=1,...,n
 * Constraints:
 *      1 <= n <= 100, 1<= a_i <= 10^3 , i=1,...,n
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

bool isGreater(int a, int b) {
  std::stringstream ab_str, ba_str;
  int ab, ba;
  ab_str << a << b;
  ba_str << b << a;
  ab_str >> ab;
  ba_str >> ba;
  return (ab > ba);
}

void insertion_sort(vector<int> &p, int n) {
  int i = 1, j;
  double x;
  while (i < n) {
    x = p[i];
    j = i - 1;
    while (j >= 0 && isGreater(x, p[j])) {
      p[j + 1] = p[j];
      j = j - 1;
    }
    p[j + 1] = x;
    i++;
  }
  return;
}

string largest_number(vector<int> a) {
  int n = a.size();
  std::stringstream ret;

  insertion_sort(a, n);
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
