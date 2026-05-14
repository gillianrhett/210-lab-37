// COMSC-210 | Lab 37 | Gillian Rhett
#include <iostream>
using namespace std;

int stringSum(string);

int main() {
    //Write a function sum_ascii() that receives a single string and returns the sum of that string's character's ASCII values. 

/*You can cast from a character to an integer easily. Look at the demo code in the starter repl. You cast a character-to-an-int and an int-to-a-character by prefacing the variable with (int) or (char) accordingly:

    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;   << prints the ASCII value of 'A'
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;  << prints the char equivalent of 66

Test your function by providing it with any string, double-checking the ASCII values by hand to validate your code's calculations.

Commit/push your code one additional time at the end of this part with the commit comment "Milestone 1."
  */
    string word = "Hello"; // 72 + 101 + 108 + 108 + 111 = 500
    cout << stringSum(word) << endl;
    word = "world!"; // 119 + 111 + 114 + 108 + 100 + 33 = 585
    cout << stringSum(word) << endl;

    return 0;
}

int stringSum(string str_in) {
    int sum = 0;
    for (char c : str_in)
        sum += c;
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
