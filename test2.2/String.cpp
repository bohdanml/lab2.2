#include "String.h"
#include <cstring>



String::String() : str(nullptr), length(0) {}
String::String(const char* s) : length(strlen(s)) {
    str = new char[length + 1];
    strcpy_s(str, length + 1, s);
}
String::String(const String& other) : length(other.length) {
    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str);
}


String::~String() {
    delete[] str;
}


const char* String::getStr() const {
    return str;
}
size_t String::getLength() const {
    return length;
}


String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }
    return *this;
}
std::ostream& operator<<(std::ostream& os, const String& s) {
    return os << s.str;
}
std::istream& operator>>(std::istream& is, String& s) {
    char buffer[1000];
    is.getline(buffer, 1000);
    s = String(buffer);
    return is;
}
String operator+(const String& s1, const String& s2) {
    String result;
    result.length = s1.length + s2.length;
    result.str = new char[result.length + 1];
    strcpy_s(result.str, result.length + 1, s1.str);
    strcat_s(result.str, result.length + 1, s2.str);
    return result;
}
String operator-(const String& s1, const String& s2) {
    String result = s1;
    char* substr = strstr(result.str, s2.str);
    if (substr != nullptr) {
        memmove(substr, substr + strlen(s2.str), strlen(substr + strlen(s2.str)) + 1);
        result.length = strlen(result.str);
    }
    return result;
}
int operator*(const String& s1, const String& s2) {
    const char* substr = strstr(s1.str, s2.str);
    if (substr != nullptr)
        return static_cast<int>(substr - s1.str);
    else
        return -1;
}


String::operator const char* () const {
    return str;
}