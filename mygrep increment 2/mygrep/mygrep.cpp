#include <iostream>
#include <string>
#include <fstream>



void findtext(std::string, std::string, bool);


int main(int argc, char* argv[])
{
    if (argc == 1) {

        std::string text;
        std::string search;

        std::cout << "Give a string string which to search for: ";
        std::getline(std::cin, text);
        std::cout << "Give search string: ";
        std::getline(std::cin, search);

        findtext(text, search, false);

        return 0;
    }

    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <search_word> <filename> or leave empty for test search." << std::endl;
        return 1;
    }

    std::string search = argv[1];
    std::string filename = argv[2];

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not find or open file " << filename << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
        findtext(line, search, true);
    }

    file.close();

    return 0;
}

void findtext(const std::string text, const std::string search, bool searchFromFile = false) {

    size_t position = text.find(search);

    if (searchFromFile) {
        if (position != std::string::npos) {
            std::cout << text << std::endl;
        }
    }
    else {

        if (position != std::string::npos) {
            std::cout << "\"" << search << "\"" << " was found in " << "\"" << text << "\"" << " at position: " << position << std::endl;
        }
        else {
            std::cout << "\"" << search << "\" was not found in " << "\"" << text << "\"." << std::endl;
        }
    }
}
