// COMSC-210 | Lab 37 | Gillian Rhett
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);

const string FILENAME = "lab-37-data-3.txt";
//const string FILENAME = "testdata.txt";

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
    /* Milestone 2
    int grand_total = 0;
    // read each string from the file and add its int value to the grand total
    string str_in; // for getting each line from the file
    while(inFile >> str_in) {
        grand_total += sum_ascii(str_in);
    }

    cout << grand_total << endl; // it should be 69893419
    // I got 69894129, difference is 710. It's getting the last line twice
    // fixed by putting inFile >> str_in in the while condition instead of !eof
    */

//We'll now create the hash table data structure. It'll be a map comprised of an int and a list as key-value pairs:
//    keys that are integers
//    values that are std::lists

//Create the std::map named hash_table. The key in the map is an int, the hash index. The value in a map is a std::list, which will contain the 12-character codes from the file that all map to that hash index.
    map <int, list<char>> hash_table;
    string str_in; // for getting each line from the file
//When codes are read from the file, send the code to your function. Receive its hash index that's returned from the function. Input that pair into the map (the hash index and the code string). Remember that the code string is going into a std::list, so use the appropriate method to manipulate that std::list.
    while(inFile >> str_in) {
        // create the hash and find its place in the map - works like an array? are indices still sequential?

        // store the string's chars in the list
    }

//Display just the first 100 map entries to the console to test your data structure. Remember how to access map elements with .first and .second as necessary.

//Your final submission is Milestone 3.

    return 0;
}

int gen_hash_index(string str_in) {
// generates a hash index that is the sum of the characters' ascii values
// since different strings can have the same sum, I'll use linear probing
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
