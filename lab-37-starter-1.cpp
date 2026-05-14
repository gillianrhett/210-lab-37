// COMSC-210 | Lab 37 | Gillian Rhett
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);

const string FILENAME = "lab-37-data-3.txt";
//const string FILENAME = "testdata.txt";
const int MAX_SIZE = 100185; // the number of items we need to store

int main() {

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

    map<int, list<char>> hash_table;
    string str_in; // for getting each line from the file

    // read each string from the file, compute a suitable index, and insert it in the map
    while(inFile >> str_in) {
        // create the hash
        int temp_key = gen_hash_index(str_in);

        // check whether this key is already taken
        while(hash_table.count(temp_key) > 0) {
            temp_key +=1; // get a key that isn't already taken
            if (temp_key > MAX_SIZE)
                temp_key = 0; // wrap back around to 0
            cout << temp_key << " "; // testing
        }

        // store the string's chars in the list
        for (char c : str_in)
            hash_table[temp_key].push_back(c);
    }

    // display the first 100 elements in the map
    cout << "Key\tValue" << endl;
    int max = 100;
    int i = 0;
    for (auto it = hash_table.begin(); it != hash_table.end() && i < max; ++it, ++i) {
        std::cout << it->first << "\t";
        for (char c : it->second)
            cout << c;
        cout << endl;
    }

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
