// COMSC-210 | Lab 37 | Gillian Rhett
#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(string);

//const string FILENAME = "lab-37-data-3.txt";
const string FILENAME = "testdata.txt";

int main() {

    /* Milestone 1
    string word = "Hello"; // 72 + 101 + 108 + 108 + 111 = 500
    cout << sum_ascii(word) << endl;
    word = "world!"; // 119 + 111 + 114 + 108 + 100 + 33 = 585
    cout << sum_ascii(word) << endl;
    */

    ifstream inFile; // file object to get the items from
    // try to open the file
    try {
        inFile.open(FILENAME, ios::in);
        if(inFile.fail()) 
            throw invalid_argument("file not found");
    }
    catch(invalid_argument& e) {
        cout << "Error: " << e.what();
        return -1;
    }
    
    int grand_total = 0;
    // read each string from the file and add its int value to the grand total
    string str_in; // for getting each line from the file
    while(!inFile.eof()) {
        inFile >> str_in;
        grand_total += sum_ascii(str_in);
    }

    cout << grand_total << endl; // it should be 69893419
    // I got 69894129, difference is 710. is it getting line break characters?

    return 0;
}

int sum_ascii(string str_in) {
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
