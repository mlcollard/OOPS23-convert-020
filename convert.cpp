/*
    convert.cpp

    Convert the text

    Note: The "@concerns" are for pedagogical purposes only.

    * @concerns are assume to be [in], meaning they are predefined and used in the code
    * @concerns marked [out] meaning they are produced in that section
*/

#include <iostream>
#include <string>
#include <cctype>

// output character
// @concerns output format, std::cout, output[out]
void output(char c) {
    std::cout << c;
}

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @concerns input format, argc, argv, error handling
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // conversion option
    // @concerns input format, argv, std::string, option[out]
    std::string option(argv[1]);

    // input text
    // @concerns input format, argv, std::string, text[out]
    std::string text(argv[2]);

    // convert the string according to the option
    // @concerns option, text, "--upper", "--lower"
    // @concerns std::string, std::toupper(), std::tolower(), iteration
    // @concerns error handling, std::cerr
    if (option == "--upper") {

        for (auto pc = text.begin(); pc != text.end(); ++pc)
            *pc = std::toupper(*pc);

    } else if (option == "--lower") {

        for (auto pc = text.begin(); pc != text.end(); ++pc)
            *pc = std::tolower(*pc);

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // output converted text
    // @concerns text, std::string, iteration, output
    for (auto pc = text.cbegin(); pc != text.cend(); ++pc)
        output(*pc);
    std::cout << '\n';

    return 0;
}
