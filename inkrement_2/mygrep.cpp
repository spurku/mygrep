#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int grep(const string& str, const string& _path) {
    ifstream file(_path);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << _path << endl;
        return 1;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.find(str) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matches found for \"" << str << "\" in " << _path << endl;
    }

    file.close();
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <search string> <file path>" << endl;
        return 1;
    }

    return grep(argv[1], argv[2]);
}
