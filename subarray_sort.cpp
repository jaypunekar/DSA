/*
Given an array of size atleast 2, find the smallest subarray that needs to be sorted in place so that the entire
input array becomes sorted.
If array is already sorted then print -1 , -1, else print the start and end index for the unsorted subarray

Sample Input 
[1, 2, 3, 4, 5, 8, 6, 7 ,9 ,10, 11]

Output
5, 7
 */



#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

bool outOfOrder(vector<int> v, int i) {
  if (i == 0)
    return v[i] > v[i + 1];
  if (i == v.size() - 1)
    return v[i] < v[i - 1];

  return v[i] > v[i + 1] || v[i] < v[i - 1];
}

int main() {
  vector<int> v = {1, 2, 3, 4, 7, 5};
  int lowest = INT16_MAX; int highest = INT16_MIN;

  for (int i = 0; i < v.size(); i++) {
    if (outOfOrder(v, i)) {
      lowest = min(v[i], lowest);
      highest = max(v[i], highest);
    }
  }
  if (lowest == INT16_MAX && highest == INT16_MIN) {
    cout << -1 << ", " << -1 << endl;
    return 0;
  }

  int i = 0; int j = v.size() - 1;
  while (v[i] <= lowest) {
    i++;
  }
  while (highest <= v[j]) 
    j--;
  
  cout << i << ", " << j << endl;
  return 0;
}
