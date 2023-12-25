/*
Minimum Difference
Implement a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from each array) who absolute difference is closest to zero, and returns a pair containing these two numbers, with the first number from array. Only one such pair will exist for the test.

Input

Array1 = [23, 5, 10, 17, 30]
Array2 = [26, 134, 135, 14, 19]
Output

17,19
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


pair<int,int> minDifference(vector<int> a ,vector<int> b){
    int first, second;
    int minVal = INT_MAX;
    for (int valA : a) {
        for (int valB : b) {
            int val = abs(valA - valB);
            if (val < minVal) {
                minVal = val;
                first = valA;
                second = valB;
            }
        }
    }
    return {first, second};
}

int main() {
    vector<int> a = {23, 5, 10, 17, 30};
    vector<int> b = {26, 134, 135, 14, 19};
    pair<int, int> ans = minDifference(a, b);
    cout << ans.first << " " << ans.second << endl;
}