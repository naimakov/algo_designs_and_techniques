#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h> 
#include <ctime>
#include <random>
#define BIG_VALUE 1e9

using std::vector;
using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Primitive Calculator
 * Given a positive integer n, find the minimum number of operations
 * needed to obtain the number n starting from the number 1
 * Operations: x*2, x*3, x+1
 * 
 * Input: integer n
 * Output: 
 *      1st line: integer k - minimum number of operations needed to get n from 1.
 *      2nd line: a sequence of intermediate numbers a_0=1, ..., a_k-1 = n
 *                a_i+1 = a_i + 1 or 2*a_i or 3*a_i for 0 <= i < k-1
 * Constraints: 
 *      1 <= n <= 10^6
 * Time limit: 1 sec
 * Memory limit: 512 mb
*/
void tic(int mode=0)
{ 
    if (mode==0)
      t_start = time(0);
    else
    {
      t_end = time(0);
      cout<< "Elapsed time is " << difftime(t_end,t_start) << " seconds\n";
    }
}
void toc(){ tic(1); }

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dp_optimal_sequence(int n) {
  std::vector<vector<int>> sequences(n + 1);
  std::vector<int> MinNumOps(n + 1);
  int NumOps = 0; // number of operations
  int id_ops = 0; // id of the operation: 0 - for x + 1, 1 - for 2*x, 2 - for 3*x

  MinNumOps[0] = 0;
  MinNumOps[1] = 0;
  sequences[0] = vector<int>{0};
  sequences[1] = vector<int>{1};
  for (int i = 2; i <= n; i++)
  {
    MinNumOps[i] = BIG_VALUE;
    id_ops = -1;

    NumOps = MinNumOps[i - 1] + 1;
    if (NumOps < MinNumOps[i])
    {
      MinNumOps[i] = NumOps;
      id_ops = 0;
    }
    if (i % 2 == 0)
    {
      NumOps = MinNumOps[i / 2] + 1;
      if (NumOps < MinNumOps[i])
      {
        MinNumOps[i] = NumOps;
        id_ops = 1;
      }
    }
    if (i % 3 == 0)
    {
      NumOps = MinNumOps[i / 3] + 1;
      if (NumOps < MinNumOps[i]) 
      {
        MinNumOps[i] = NumOps;
        id_ops = 2;
      }
    }
    switch (id_ops)
    {
      case 0 : 
        sequences[i] = sequences[i - 1];
        break;
      case 1 : 
        sequences[i] = sequences[i / 2];
        break;
      case 2 : 
        sequences[i] = sequences[i / 3];
        break;
    }
    sequences[i].push_back(i);
  }
  return sequences[n];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  std::cout << '\n';
  vector<int> sequence_dp = dp_optimal_sequence(n);
  std::cout << sequence_dp.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence_dp.size(); ++i) {
    std::cout << sequence_dp[i] << " ";
  }
  std::cout << '\n';
}