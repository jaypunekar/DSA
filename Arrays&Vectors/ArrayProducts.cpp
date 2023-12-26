/*
Array Products
Implement a function that takes in a vector of integers, and returns a vector of the same length, where each element in the output array is equal to the product of every other number in the input array. Solve this problem without using division.

In other words, the value at output[i] is equal to the product of every number in the input array other than input[i]. You can assume that answer can be stored inside int datatype and no-overflow will occur due to products.

Sample Input

Both inputs and outputs are vectors.

{1,2,3,4,5}
Sample Output

{120, 60, 40, 30, 24}
*/

#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> v) {
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
}

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    vector<int> prefixArray(n, 1);
    vector<int> suffixArray(n, 1);

    int prefixProduct = arr[0];
    int suffixProduct = 1;
    prefixArray[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefixArray[i] = prefixArray[i - 1] * arr[i];
    }
    
    suffixArray[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixArray[i] = suffixArray[i + 1] * arr[i];
    }
    output[0] = suffixArray[1];
    output[n - 1] = prefixArray[n - 2];
    for (int i = 1; i < n - 1; i++) {
        output[i] = (prefixArray[i - 1] * suffixArray[i + 1]);
    }
    return output;
}

int main() {
    vector<int> v = {1,2,3,4,5};
    vector<int> ans = productArray(v);
    printArray(ans);
    return 0;
}