/*
Given an array of size N, find the minimum number of swaps needed to make the array sorted

Sample Input
[5, 4, 3, 2, 1]

Output
3
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int minSwaps(vector<int> &v)
{
    int n = v.size();
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first = v[i];
        ap[i].second = i;
    }

    sort(ap, ap + n);

    int ans = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true || ap[i].second == i)
            continue;
        int node = i;
        int cycle = 0;
        while (!visited[node])
        {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle++;
        }
        ans += (cycle - 1);
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 11, 5, 4, 3, 2, 1};
    cout << minSwaps(arr) << endl;
    return 0;
}