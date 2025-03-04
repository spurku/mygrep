#include <iostream>
#include <string>
using namespace std;

int main() {
    string search_str;
    string input;

    cout << "Give a string from which to search for: ";
    getline(cin, search_str); 

    cout << "Give search string: ";
    getline(cin, input);  

    size_t found = search_str.find(input);

    if (found != string::npos) {
        cout << "\"" << input << "\"" << " found in \"" << search_str << "\" at position " << found << endl;
    } else {
        cout << "\"" << input << "\"" << " NOT found in \"" << search_str << "\"" << endl;
    }

    return 0;
}
