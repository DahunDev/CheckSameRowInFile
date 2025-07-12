#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: checkrows <filename>\n";
        return 1;
    }

    const char* filename = argv[1];
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return 1;
    }

    std::unordered_set<std::string> seen_lines;
    std::string line;
    bool duplicate_found = false;

    while (std::getline(file, line)) {
        if (seen_lines.find(line) != seen_lines.end()) {
            std::cout << "Duplicate found: \"" << line << "\"\n";
            duplicate_found = true;
        } else {
            seen_lines.insert(line);
        }
    }

    if (!duplicate_found) {
        std::cout << "No duplicate rows found.\n";
    }

    file.close();
    return 0;
}
