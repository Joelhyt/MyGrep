#include <iostream>
#include <string>



void findtext(std::string, std::string);


int main()
{
    std::string text;
    std::string search;

    std::cout << "Give a string string which to search for: ";
    std::getline(std::cin, text);
    std::cout << "Give search string: ";
    std::getline(std::cin, search);

    findtext(text, search);
}

void findtext(std::string text, std::string search) {

    size_t position = text.find(search);

    if (position != std::string::npos) {
        std::cout << "\"" << search << "\"" << " was found in " << "\"" << text << "\"" << " at position: " << position << std::endl;
    }
    else {
        std::cout << "\"" << search << "\" was not found in " << "\"" << text << "\"." << std::endl;
    }
}
