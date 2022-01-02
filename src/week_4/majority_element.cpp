#include <algorithm>
#include <iostream>
#include <vector>
#include <assert.h> 
#include <vector>
#include <ctime>
#include <random>

using std::vector;
using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Majority Element
 * Check whether an input sequence contains a majority element
 * 
 * Input: 
 *      1st line - integer n
 *      2nd line - 0 <= a_0, a_1, ... , a_{n-1}
 * Output: 
 *      1 - if {a_k} contains an element appearing more that n/2 times, 0 - otherwise
 * Constraints: 
 *      1 <= n <= 10^5, 0 <= a_i <= 10^9 for 0 <= i < n
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

int get_majority_element_naive(vector<int> &a)
{
  int curr = 0, count = 0, n = a.size();
  for(int i=0;i<n;i++)
  {
    curr = a[i];
    count = 0;
    for(int j=0;j<n;j++)
    {
      if(a[j] == curr) count++;
      if(count > n/2) return 1;
    }
  }
  return 0;
}

int get_majority_element_smart(vector<int> &a)
{
  int curr = 0, count = 0, n = a.size();
  for(int i=0;i<n;i++)
  {
    if(count == 0)
    {
      curr = a[i];
      count++;
    }
    else
    {
      if(curr == a[i]) count++;
      else count--;
    }
  }
  count = 0;
  for(int i=0;i<n;i++)
  {
    if(a[i] == curr) count++;
  }
  return (count > n/2);
}

int get_majority_element_divconq(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //std::cout << (get_majority_element_divconq(a, 0, a.size()) != -1) << '\n';
  std::cout << get_majority_element_naive(a) << "\n";
  std::cout << get_majority_element_smart(a) << "\n";
}
