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

    if (argc != 3 && argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <options -ol , -olo> <search_word> <filename> or leave empty for test search." << std::endl;
        return 1;
    }


    if (argc == 3) {
        std::string line;
        std::string search = argv[1];
        std::string filename = argv[2];
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return 1;
        }
        while (std::getline(file, line)) {
            findtext(line, search, true);
        }
        file.close();
    }
    else if (argc == 4) {

        int lineNumber{ 1 };
        std::string line;
        std::string options = argv[1];
        std::string search = argv[2];
        std::string filename = argv[3];
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return 1;
        }
        if (options == "-ol") {
            while (std::getline(file, line)) {
                if (line.find(search) != std::string::npos) {
                    std::cout << lineNumber << ":";
                    findtext(line, search, true);
                }
                lineNumber++;
            }
        }
        else if (options == "-olo") {
            int occurences{ 0 };
            while (std::getline(file, line)) {
                if (line.find(search) != std::string::npos) {
                    std::cout << lineNumber << ":";
                    findtext(line, search, true);
                    occurences++;
                }
                lineNumber++;
            }
            std::cout << "\nOccurences of lines containing \"" << search << "\": " << occurences << std::endl;
        }
        else {
            std::cerr << "\nError: Incorrect options.\n\n" << "Usage: " << argv[0] << " <options -ol , -olo> <search_word> <filename> or leave empty for test search." << std::endl;
            return 1;
        }

        file.close();
    }
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
            std::cout << "\"" << search << "\" was NOT found in " << "\"" << text << "\"." << std::endl;
        }
    }
}
