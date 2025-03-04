#include <iostream>
#include <fstream>
#include <string>

void search_in_file(const std::string& file_name, const std::string& search_string, bool show_line_numbers, bool show_count) {
    std::ifstream file(file_name);
    if (!file) {
        std::cerr << "File not found: " << file_name << std::endl;
        return;
    }

    std::string line;
    int count = 0;
    int line_num = 0;

    while (std::getline(file, line)) {
        ++line_num;
        if (line.find(search_string) != std::string::npos) {
            count++;
            if (show_line_numbers) {
                std::cout << line_num << ": " << line << std::endl;
            } else {
                std::cout << line << std::endl;
            }
        }
    }

    if (show_count) {
        std::cout << "Occurrences of lines containing \"" << search_string << "\": " << count << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::string large_string, search_string;

    std::cout << "Give a string from which to search for: ";
    std::getline(std::cin, large_string);
    std::cout << "Give search string: ";
    std::getline(std::cin, search_string);

    size_t position = large_string.find(search_string);

    if (position != std::string::npos) {
        std::cout << "\"" << search_string << "\" found in \"" << large_string 
                  << "\" in position " << position << std::endl;
    } else {
        std::cout << "\"" << search_string << "\" NOT found in \"" << large_string << "\"" << std::endl;
    }

    bool show_line_numbers = false;
    bool show_count = false;
    
    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-l") {
            show_line_numbers = true;
        }
        if (arg == "-o") {
            show_count = true;
        }
    }

    if (argc > 1) {
        std::string file_name = argv[1];
        search_in_file(file_name, search_string, show_line_numbers, show_count);
    }

    return 0;
}
