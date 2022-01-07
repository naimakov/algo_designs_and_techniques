#include <iostream>
#include <vector>
#include <assert.h> 
#include <ctime>
#include <random>
#define BIG_VALUE 1e9

using std::vector;
using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Money Change again
 * Apply dynamic programming for solving the Money Change Problem
 * for denominations 1, 3 and 4
 * 
 * Input: integer n - money
 * Output: integer m - minimum number of coins 
 *         with denominations 1, 3 and 4 that changes money
 * Constraints: 
 *      1 <= n <= 10^3
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

int get_change(int m) {
  vector<int> MinNumCoins(m + 1), coins{1,3,4};
  int NumCoins = 0;

  MinNumCoins[0] = 0;
  for (int i = 1; i <= m; i++){
      MinNumCoins[i] = BIG_VALUE;
      for (int j = 0; j < coins.size(); j++){
          if (i >= coins[j]){
              NumCoins = MinNumCoins[i - coins[j]] + 1;
              if (NumCoins < MinNumCoins[i]) MinNumCoins[i] = NumCoins;
          }
      }
  }
  return MinNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
