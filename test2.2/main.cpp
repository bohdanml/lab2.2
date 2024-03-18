#include "String.h"


int main() {
    String s1;
    std::cout << "Enter a string: ";
    std::cin >> s1;

    String s2("in the sky!");
    String s3 = s1 + s2;

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;

    s3 = s3 - String("in the sky!");
    std::cout << "After removing 'in the sky!': " << s3 << std::endl;

    String s4("lo");
    int pos = s1 * s4;
    if (pos != -1)
        std::cout << "Position of 'lo' in s1: " << pos << std::endl;
    else
        std::cout << "'lo' not found in s1." << std::endl;

    const char* strPtr = static_cast<const char*>(s1);
    std::cout << "String pointer: " << strPtr << std::endl;

    return 0;
}

