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
#include <algorithm>
#include <unordered_map>

// output character
// @concerns output format, std::cout, output[out]
void output(char c) {
    std::cout << c;
}

typedef void(*Conversion)(char& c);

// option to conversion mapping
// @concerns "--upper", "--lower", std::toupper, std::tolower, conversionOption[out]
const std::unordered_map<std::string, Conversion> conversionOption{
    { "--upper", [](char& c) { c = std::toupper(c); } },
    { "--lower", [](char& c) { c = std::tolower(c); } },
};

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

    // maps from the option name to a conversion function
    // @concerns option, conversionOption
    // @concerns std::string, Conversion, convert[out]
    // @concerns error handling, std::cerr
    auto conversionEntry = conversionOption.find(option);
    if (conversionEntry == conversionOption.end()) {
        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }
    const Conversion convert = conversionEntry->second;

    // convert the text according to the conversion function
    // @concerns text, std::for_each, convert
    std::for_each(text.begin(), text.end(), convert);

    // output converted text
    // @concerns text, std::for_each, output
    std::for_each(text.begin(), text.end(), output);
    std::cout << '\n';

    return 0;
}
