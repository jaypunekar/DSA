/*
Given an array containing N integers, find the length of the longest band.

A band is defined as the longest subsequence which can be reordered in such a manner that all
elements appear consicutive (i.e. with absolute difference of 1 between neighbouring elements)

Input
[1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 6]

Output
[8]

Explaination
Largest subsequence containing consecutive numbers is [0, 1, 2, 3, 4, 5, 6, 7]

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestBand(vector<int> v) {
  unordered_set<int> u;
  int maxBand = 0;
  for (int i : v) {
    u.insert(i);
  }

  for (int i : v) {
    int cnt = 1;
    if (u.find(i - 1) == u.end()) {
      while (u.find(i + 1) != u.end()) {
        cnt++; 
        i++;
      }
    }
    maxBand = max(maxBand, cnt);
  }
  return maxBand;
}

int main() {
  vector<int> v = {1, 9, 3, 0, 18, 5, 2, 4, 10, 8, 7, 12, 6};

  int ans = longestBand(v);
  cout << ans << endl;

  return 0;
}

