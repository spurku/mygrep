#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>
#ifdef _WIN32
#else
#include <unistd.h>
#endif

using namespace std;

typedef struct flags {
    bool linenum = false;
    bool occurrences = false;
} flags;

int grep(string str, string path, flags& flags) {
    ifstream file(path);
    string line;
    uint32_t occurrences_count = 0;
    uint32_t line_count = 1;

    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << path << endl;
        return -1;
    }

    while (getline(file, line)) {
        if (line.find(str) != string::npos) {
            if (flags.linenum) {
                cout << line_count << ": ";
            }
            cout << line << endl;
            occurrences_count++;
        }
        line_count++;
    }
    file.close();

    if (flags.occurrences) {
        cout << endl << "Occurrences of lines containing \"" << str << "\": " << occurrences_count << endl;
    }

    return 0;
}

void setflags(const string& optarg, flags& flags) {
    if (optarg.find("o") != string::npos) {
        flags.occurrences = true;
    }
    if (optarg.find("l") != string::npos) {
        flags.linenum = true;
    }
}

int main(int argc, char **argv) {
    flags flags;

    int opt;
    while ((opt = getopt(argc, argv, "o:l")) != -1) {
        switch (opt) {
            case 'o':
                setflags(optarg, flags);
                break;
            case 'l':
                flags.linenum = true;
                break;
            default:
                cerr << "Usage: " << argv[0] << " [-o] [-l] <search string> <file>" << endl;
                return 1;
        }
    }

    if (optind + 1 >= argc) {
        cerr << "Usage: " << argv[0] << " <search string> <file>" << endl;
        return 1;
    }

    string search_string = argv[optind];
    string file_path = argv[optind + 1];

    return grep(search_string, file_path, flags);
}
