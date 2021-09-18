#include <algorithm>
#include <iostream>
#include <assert.h> 
#include <vector>
#include <ctime>
#include <random>

using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Maximum Advertisement Revenue
 * Given 2 seq-s a_i (profit per click of the i-th ad) and
 * b_i (average number of clicks per day of the i-th slot),
 * partition them into n pairs (a_i,b_j) 
 * so that the sum of products is maximized.
 * 
 * Input: 
 *      integers n, a_i, b_i - number of ads, profits per click 
 *      and average numbers of clicks
 * Output: 
 *      max value of \sum_{i=1}^n a_i c_i where c_i is a permutation of b_i
 * Constraints: 
 *      1 <= n <= 10^3, -10^5 <= a_i, b_i <= 10^5 
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

void insertion_sort(int* p, int n)
{
    int i = 1,j;
    double x;
    while (i < n)
    {
        x = p[i];
        j = i - 1;
        while (j >= 0 && p[j] < x)
        {
            p[j+1] = p[j];
            j = j-1;
        }
        p[j+1] = x;
        i++;
    }
    return;
}

long long max_dot_product(int* a, int* b, int n) 
{
    long long result = 0;

    if (n == 0) return result;

    insertion_sort(a,n);
    insertion_sort(b,n);

    for (int i = 0; i < n; i++) {
    result += ((long long) a[i]) * b[i];
    }
    return result;
}

int main() 
{
    int n;
    std::cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) 
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) 
    {
        std::cin >> b[i];
    }
    tic();
    std::cout << max_dot_product(a, b, n) << std::endl;
    toc();
}
