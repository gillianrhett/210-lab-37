// COMSC-210 | Lab 37 | Gillian Rhett
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);
list<char> convert_s_to_clist(string);
bool search_map(int, map<int, list<char>>&);

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
    map<int, list<char>> hash_table; // I'll get it to work with a string first, then convert to a list of chars
    string str_in; // for getting each line from the file
//When codes are read from the file, send the code to your function. Receive its hash index that's returned from the function. Input that pair into the map (the hash index and the code string). Remember that the code string is going into a std::list, so use the appropriate method to manipulate that std::list.
    while(inFile >> str_in) {
        // create the hash
        int temp_key = gen_hash_index(str_in);

        // check whether this key is already taken
        while(search_map(temp_key, hash_table))
            temp_key += 1; // get a key that isn't already taken, via simple linear probe
        
        list<char> char_list = convert_s_to_clist(str_in);
        // store the string's chars in the list
        hash_table[temp_key] = {char_list};
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

list<char> convert_s_to_clist(string str_in) {
// put the chars from a string into a list
    list<char> c_list;
    for(char c : str_in)
        c_list.push_back(c);
    return c_list;
}

bool search_map(int search_key, map<int, string>& map_to_search) {
    auto it = map_to_search.find(search_key);
    return it != map_to_search.end();
}
