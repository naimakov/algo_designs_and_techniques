#include <assert.h>

#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

time_t t_start, t_end;

/**
 * Collecting Signatures
 * Given n seg-s [a_i,b_i], find minimal number of points m
 * so that each segment contains at least one point.
 *
 * Input:
 *      integers n, a_i, b_i - number of segments,
 *      left and right ends of segments
 * Output:
 *      min number of points and their coordinates
 * Constraints:
 *      1 <= n <= 100, 0 <= a_i <= b_i <= 10^9
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

struct Segment {
  int start, end;
};

void insertion_sort(vector<Segment> &segments) {
  int i = 1, j;
  int n = segments.size();
  Segment x;
  while (i < n) {
    x = segments[i];
    j = i - 1;
    while (j >= 0 && segments[j].end > x.end) {
      segments[j + 1].start = segments[j].start;
      segments[j + 1].end = segments[j].end;
      j = j - 1;
    }
    segments[j + 1].start = x.start;
    segments[j + 1].end = x.end;
    i++;
  }
  return;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  insertion_sort(segments);
  int x = 0;

  while (!segments.empty()) {
    x = segments.front().end;
    segments.erase(segments.begin());
    while (!segments.empty() && x >= segments.front().start) {
      segments.erase(segments.begin());
    }
    points.push_back(x);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  tic();
  vector<int> points = optimal_points(segments);
  toc();
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
