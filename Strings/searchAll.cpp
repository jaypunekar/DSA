/*
Find all occurences of a word in a string
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string paragraph = "React js is a javascript library. React is popularly know for its easy of use. React is considered on of the easier frameworks.";
    string word = "React";

    int index = paragraph.find(word);
    int occurences = 0;
    while (index != -1) {
        occurences++;
        cout << index << endl;
        index = paragraph.find(word, index + occurences);
    }

    return 0;
}