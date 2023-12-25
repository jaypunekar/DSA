/*
Given an array containing N integers, and a number S denoting a target sum

Find a triplet that adds up to the number S
*/

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> pairSum(vector<int> v, int i, int j, int sum) {
    vector<int> ans;
    while (i < j) {
        if (v[i] + v[j] < sum) {
            i++;
        } else if (v[i] + v[j] > sum) {
            j--;
        } else {
            ans.push_back(v[i]);
            ans.push_back(v[j]);
            return ans;
        }
    }
    ans.push_back(0);
    ans.push_back(0);
    return ans;
}

void findTriplets(vector<int> v, int sum) {
    for (int i = 0; i < v.size(); i++) {
        int remaining = sum - v[i];
        vector<int> u = pairSum(v, i + 1, v.size() - 1, remaining);
        if (u[0] != 0 && u[1] != 0) {
            cout << v[i] << " " << u[0] << " " << u[1] << endl;
        }
    }
}

int main() {
    vector<int> v = {1, 4, 3, 5, 9, 8, 7};
    int sum = 9;
    sort(v.begin(), v.end());
    findTriplets(v, sum);
    return 0;
}