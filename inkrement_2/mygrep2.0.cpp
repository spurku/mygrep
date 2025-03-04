# include <iostream>
# include <string>
# include <fstream>
using namespace std;

int grep(string str, string _path) {
    ifstream file(_path);
    string line;
    if (!file.is_open()) {
        return 1;
    }

    while (getline(file, line)) {
        if (line.find(str) != string::npos) {
            cout << line << endl;
        }
    }

    file.close();
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <search string> <file path>" << endl;
        return 0;
    }

    grep(argv[1], argv[2]);
}