/*
Given a string, write a function to replace all spaces with '%20' . It is given that
the string has sufficient space at the end to fit additional characters.

Input:
"Hello, world!"

Output:
"Hello,%20world!"
*/

#include <iostream>
using namespace std;

void replaceSpace(char* input, int n) {
    int spaces = 0;
    n = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            spaces++;
        }
        n++;
    }
    
    int last = n + (spaces * 2);
    for (int i = n - 1; i >= 0; i--) {
        if (input[i] != ' ') {
            input[last - 1] = input[i];
            last--;
        } else if (input[i] == ' ') {
            input[last - 1] = '0';
            input[last - 2] = '2';
            input[last - 3] = '%';
            last -= 3;
        }
    }
}

int main() {
    char input[10000];
    cin.getline(input, 1000);
    replaceSpace(input, 1000);
    cout << input << endl;
    return 0;
}
