#include <iostream>
#include <cassert>
#include <assert.h> 
#include <vector>
#include <ctime>
#include <random>

using std::vector;
using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Binary Search
 * Implement the binary search algorithm.
 * 
 * Input: 
 *      1st line - integers n and 0<a_0 < a_1 < ... < a_{n-1}
 *      2nd line - integers k and 0<b_0 < b_1 < ... < b_{k-1}
 * Output: 
 *      for 0<=i<=k-1 output 0<=j<=n-1 : a_j = b_i or -1 if no j exists
 * Constraints: 
 *      1 <= n,k <= 10^4, 1 <= a_i, b_k <= 10^9 
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

int binary_search(const vector<int> &a, int x) {
  int left = 0, mid = 0, right = (int)a.size()-1; 
  while(left <= right)
  {
    mid = left + (right-left)/2;
    if(a[mid] == x) return mid;
    else if(a[mid] < x) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

void StressTest(int numIter, int range_n)
{
    int n,k;
    std::uniform_int_distribution<int> rand_n(1,range_n);
    std::random_device rd;
    std::mt19937 re(rd());
    int i;
    for(i=0;i<numIter;++i)
    {
        n = rand_n(re);
        vector<int> a(n);
        for(int j = 0; j < n; j++)
        {
            a[j] = 2*j;
        }
        std::cout << "iteration #" << i << ": n=" << n <<"\n";
        k = rand_n(re);
        if(linear_search(a,k) != binary_search(a,k))
        {
            std::cout << "Error: n= " << n <<"\n";
            break;
        }    
    }
    if(i == numIter)
        std::cout << "All tests passed!";
}

int main() {
    
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
      std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
      //replace with the call to binary_search when implemented
      std::cout << linear_search(a, b[i]) << ' ';
    }
    std::cout << '\n';
    for (int i = 0; i < m; ++i) {
      //replace with the call to binary_search when implemented
      std::cout << binary_search(a, b[i]) << ' ';
    }
    
    int nIter, range_n;
    std::cin >> nIter >> range_n;
    StressTest(nIter,range_n);
}
