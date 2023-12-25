/*
Maximum Subarray Sum
Implement a function that takes an input a vector of integers,
and prints the maximum subarray sum that can be formed.
A subarray is defined as consecutive segment of the array.
If all numbers are negative, then return 0.

Input
{-1,2,3,4,-2,6,-8,3}

Output
13
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int maxSubarraySum(vector<int> v) {
    int maxSum = 0;
    int currSum = 0;
    for (int i : v) {
        currSum += i;
        maxSum = max(maxSum, currSum);
        if (currSum <= 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> v = {-1,2,3,4,-2,6,-8,3};
    int ans = maxSubarraySum(v);
    cout << ans << endl;
    return 0;
}