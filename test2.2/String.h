#pragma once

#include <iostream>

class String {
private:
    char* str;
    size_t length;

public:
    
    String();
    String(const char* s);
    String(const String& other);

    
    ~String();

   
    const char* getStr() const;
    size_t getLength() const;

    
    String& operator=(const String& other);
    friend std::ostream& operator<<(std::ostream& os, const String& s);
    friend std::istream& operator>>(std::istream& is, String& s);
    friend String operator+(const String& s1, const String& s2);
    friend String operator-(const String& s1, const String& s2);
    friend int operator*(const String& s1, const String& s2);

    
    operator const char* () const;
};