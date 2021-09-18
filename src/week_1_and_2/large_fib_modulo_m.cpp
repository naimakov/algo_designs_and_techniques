#include <iostream>
#include <vector>
#include <ctime>
#include <stack>
#include <random>

using std::vector;
using std::cin;
using std::cout;

time_t t_start, t_end;

/**
 * Fibonacci Number Again
 * Given two integers n and m, find F_n mod m
 * Input: integer n and m given in the same line separated by space.
 * Output: F_n mod m
 * Constraints: 1<=n<=10^18, 2<=m<=10^5
 * Time limit: 1 sec
 * Memory limit: 512 mb
*/
void tic(int mode=0){
 
 if (mode==0)
  t_start = time(0);
 else{
  t_end = time(0);
  cout<< "Elapsed time is " << difftime(t_end,t_start) << " seconds\n";
 }

}
void toc(){ tic(1); }

unsigned long long get_fibonacci_huge_naive(unsigned long long n, unsigned long long m) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current  = 1;

    for (unsigned long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current;
}

unsigned long long get_pisano_period(unsigned long long m)
{
    if (m == 1) return 1;
    unsigned long long previous = 0;
    unsigned long long current  = 1;
    unsigned long long period = 0;

    for (unsigned long long i = 0; i < m*m; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        if (previous == 0 && current == 1)
        {
           period = i + 1;
           break;
        }
    }
    return period;
}

unsigned long long get_fibonacci_huge_fast(unsigned long long n, unsigned long long m) {
    if (n <= 1)
        return n;
    unsigned long long period = get_pisano_period(m);

    n = n % period;
    if (n <= 1)
        return n;
    unsigned long long previous = 0;
    unsigned long long current  = 1;

    for (unsigned long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }
    return current;
}

void StressTest(int numIter)
{
    unsigned long long n, m;
    std::uniform_int_distribution<unsigned long long> rand_n(1,10e5), rand_m(2,10e5);
    std::random_device rd;
    std::mt19937 re(rd());
    for(int i=0;i<numIter;++i)
    {
        n = rand_n(re);
        m = rand_m(re);
        //if(i % 5 == 0)
            std::cout << "iteration #" << i << ": n=" << n << ", m=" << m << "\n";
        if(get_fibonacci_huge_naive(n,m) != get_fibonacci_huge_fast(n,m))
        {
            std::cout << "Error: n= " << n << ", m=" << m << "\n";
            break;
        }    
    }
    std::cout << "All tests passed!";
}
int main() 
{
    //unsigned long long n, m;
    //std::cin >> n >> m;
    //tic();
    //std::cout << get_pisano_period(m) << '\n';
    //std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    //toc();
    int nIter;
    std::cin >> nIter;
    StressTest(nIter);
}
