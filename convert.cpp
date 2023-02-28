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

// output text
// @concerns output format, output, std::string, iteration, outputText[out]
void outputText(const std::string& s) {

    for (auto pc = s.cbegin(); pc != s.cend(); ++pc)
        output(*pc);
 }

typedef void(*Conversion)(char& c);

// apply a function to each element in the range of the string [begin, end)
void myforeach(std::string::iterator begin, std::string::iterator end, Conversion convert) {

    for (auto pc = begin; pc != end; ++pc)
        convert(*pc);
}

void upper(char& c) {
    c = std::toupper(c);
}

void lower(char& c) {
    c = std::tolower(c);
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

        myforeach(text.begin(), text.end(), upper);

    } else if (option == "--lower") {

        myforeach(text.begin(), text.end(), lower);

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // output converted text
    // @concerns text, outputText
    outputText(text);
    std::cout << '\n';

    return 0;
}
