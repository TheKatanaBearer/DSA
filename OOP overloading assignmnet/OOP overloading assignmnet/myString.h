#pragma once


#include<iostream>

class mystring {
private:
    char* strdata;
    int strlength;

    // Helper function to convert the integer to string
    void inttostring(int n, char* buffer);

public:
    // Constructors
    mystring();
    mystring(int n);
    mystring(const char* str);
    mystring(const mystring& other);

    // Destructor
    ~mystring();

    // Assignment operator
    mystring& operator=(const mystring& other);

    // Concatenation operator
    mystring operator+(const mystring& other) const;

    // Concatenation assignment operator
    mystring& operator+=(const mystring& other);

    // Subscript operator
    char& operator()(int index);

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& out, const mystring& mystr);

    // Stream extraction operator
    friend std::istream& operator>>(std::istream& is, mystring& mystr);

    // Relational operators
    bool operator<(const mystring& other) const;
    bool operator<=(const mystring& other) const;
    bool operator>(const mystring& other) const;
    bool operator>=(const mystring& other) const;
    bool operator==(const mystring& other) const;
    bool operator!=(const mystring& other) const;
};


