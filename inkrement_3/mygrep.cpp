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
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " -o[options] search_string file_name" << std::endl;
        return 1;
    }

    std::string options = argv[1];
    std::string search_string = argv[2];
    std::string file_name = argv[3];

    bool show_line_numbers = false;
    bool show_count = false;

    if (options.size() > 2 && options[0] == '-' && options[1] == 'o') {
        for (size_t i = 2; i < options.size(); ++i) {
            if (options[i] == 'l') show_line_numbers = true;
            if (options[i] == 'o') show_count = true;
        }
    } else {
        std::cerr << "Invalid options format. Use -o[options] (e.g., -ol, -oo)." << std::endl;
        return 1;
    }

    search_in_file(file_name, search_string, show_line_numbers, show_count);
    return 0;
}
