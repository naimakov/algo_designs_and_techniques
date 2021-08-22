#include <iostream>
#include <vector>
#include <ctime>

using std::vector;
using std::cin;
using std::cout;

time_t t_start, t_end;

void tic(int mode=0){
 
 if (mode==0)
  t_start = time(0);
 else{
  t_end = time(0);
  cout<< "Elapsed time is " << difftime(t_end,t_start) << " seconds\n";
 }

}
void toc(){ tic(1); }

int MaxPairwiseProduct(const vector<int>& numbers) {
  int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        //cin >> numbers[i];
     	numbers[i] = i;
    }
	tic();
    int result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
 	toc();
    return 0;
}
