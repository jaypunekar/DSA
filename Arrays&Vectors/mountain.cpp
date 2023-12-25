#include <iostream>
#include <vector>
using namespace std;

int highestMountain(vector<int> v) {
    int maxHeight = 0;
    for (int i = 1; i < v.size() - 1;) {
        int currHeight = 1;
        // cout << i << endl;
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            int j = i;
            while (v[j] >= 1 && v[j] > v[j - 1]) {
                currHeight++;
                j--;
            }
            while (v[i] <= v.size() - 1 && v[i] > v[i + 1]) {
                currHeight++;
                i++;
            }
        } else {
            i++;
        }
        maxHeight = max(currHeight, maxHeight);
    }

    return maxHeight;
}

int main() {
    vector<int> v = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0, 1, 2, 3, -2, 4};
    // vector<int> v = { 1, 2, 3, 4, 5, 4, 3, 2, 0, 10};

    int ans = highestMountain(v);
    cout << ans << endl;
}