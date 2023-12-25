/*
Given n non-negative integer representing an elevated map where the width of each bar is 1, compute
how much water it can trap after raining.

Input
heights = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

Output
6
*/

#include <iostream>
#include <vector>
using namespace std;

// void printVec(vector<int> v) {
//   for (auto i : v) {
//     cout << i << " ";
//   }
//   cout << endl;
// }

int main() {
  vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> left(v.size());
  vector<int> right(v.size());
  int currmaxI = 0, currmaxJ = 0;

  if (v.size() == 2) {
    cout << 0 << endl;
    return 0;
  }
  
  for (int i = 0; i < v.size(); i++) {
    left[i] = max(v[i], currmaxI);
    currmaxI = left[i];
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    right[i] = max(v[i], currmaxJ);
    currmaxJ = right[i];
  }

  // printVec(left);
  // printVec(right);
  int water = 0;
  for (int i = 0; i < v.size(); i++) {
    water += abs(min(left[i], right[i]) - v[i]);
  }
  cout << water << endl;
  return 0;
}

