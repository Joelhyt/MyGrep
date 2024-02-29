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

void findtext(std::string a, std::string b) {

    size_t position = a.find(b);

    if (position != std::string::npos) {
        std::cout << "\"" << b << "\"" << " was found in " << "\"" << a << "\"" << " at position: " << position << std::endl;
    }
    else {
        std::cout << "\"" << b << "\" was not found in " << "\"" << a << "\"." << std::endl;
    }
}
