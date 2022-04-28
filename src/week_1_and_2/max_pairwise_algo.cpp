#include <ctime>
#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

time_t t_start, t_end;

/**
 * Maximum Pairwise Product
 * Find the maximum product of two distinct numbers
 * in a sequence of non-negative integers
 * Input: int n - number of integers
 *        a_1,...,a_n integers
 * Output: The maximum pairwise product
 * Constraints: 2<=n<=2*10^5; 0<=a_1,...,a_n<=2*10^5
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

unsigned long long MaxPairwiseProductNaive(
    const vector<unsigned long long> &numbers) {
  unsigned long long result = 0, temp = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      temp = numbers[i] * numbers[j];
      if (temp > result) {
        result = temp;
      }
    }
  }
  return result;
}

unsigned long long MaxPairwiseProductFast(vector<unsigned long long> &numbers) {
  int n = numbers.size();
  int index = 0;

  if (n == 2) {
    return numbers[0] * numbers[1];
  }
  for (int i = 1; i < n; ++i) {
    if (numbers[i] > numbers[index]) {
      index = i;
    }
  }
  std::swap(numbers[index], numbers[n - 1]);
  index = 0;
  for (int i = 1; i < n - 1; ++i) {
    if (numbers[i] > numbers[index]) {
      index = i;
    }
  }
  std::swap(numbers[index], numbers[n - 2]);

  return numbers[n - 1] * numbers[n - 2];
}

unsigned long long MaxPairwiseProductFast2(
    vector<unsigned long long> &numbers) {
  int n = numbers.size();
  std::stack<int> stack;
  stack.push(0);
  if (n == 2) {
    return numbers[0] * numbers[1];
  }

  for (int i = 1; i < n; ++i) {
    if (numbers[i] >= numbers[stack.top()]) {
      stack.push(i);
    }
  }
  unsigned long long result = numbers[stack.top()];
  stack.pop();
  result *= numbers[stack.top()];

  return result;
}

int main() {
  int n;
  cin >> n;
  vector<unsigned long long> numbers(n);
  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }
  tic();
  unsigned long long result = MaxPairwiseProductFast2(numbers);
  cout << result << "\n";
  toc();
  return 0;
}
