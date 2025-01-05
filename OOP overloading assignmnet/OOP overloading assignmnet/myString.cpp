#include "mystring.h"
#include <cstring>

void mystring::inttostring(int n, char* buffer) {
    int num = n;
    int i = 0;

    // Checking each digit
    do {
        buffer[i++] = num % 10 + '0';
        num = num / 10;
    } while (num != 0);

    // String reversal
    int start = 0;
    int end = strlen(buffer) - 1;

    while (start < end) {
        // Swapping characters
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;

        start++;
        end--;
    }
}

// Constructors
mystring::mystring() : strdata(NULL), strlength(0) {}

mystring::mystring(int n) {
    char temp[15];
    inttostring(n, temp);
    strlength = strlen(temp);
    strdata = new char[strlength + 1];
    strcpy(strdata, temp);
}

mystring::mystring(const char* str) : strlength(strlen(str)) {
    strdata = new char[strlength + 1];
    strcpy(strdata, str);
}

mystring::mystring(const mystring& other) : strlength(other.strlength) {
    strdata = new char[strlength + 1];
    strcpy(strdata, other.strdata);
}

// Destructor
mystring::~mystring() {
    delete[] strdata;
}

// Assignment operator
mystring& mystring::operator=(const mystring& other) {
    if (this != &other) {
        delete[] strdata;
        strlength = other.strlength;
        strdata = new char[strlength + 1];
        strcpy(strdata, other.strdata);
    }
    return *this;
}

// Concatenation operator
mystring mystring::operator+(const mystring& other) const {
    mystring result(strlength + other.strlength);
    strcpy(result.strdata, strdata);
    strcat(result.strdata, other.strdata);
    return result;
}

// Concatenation assignment operator
mystring& mystring::operator+=(const mystring& other) {
    *this = *this + other;
    return *this;
}

// Subscript operator
char& mystring::operator()(int index) {
    return strdata[index];
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& out, const mystring& mystr) {
    out << mystr.strdata;
    return out;
}

// Stream extraction operator
std::istream& operator>>(std::istream& is, mystring& mystr) {
    char temp[256];
    is >> temp;
    mystr = mystring(temp);
    return is;
}

// Relational operators
bool mystring::operator<(const mystring& other) const {
    int minlength = (strlength < other.strlength) ? strlength : other.strlength;
    for (int i = 0; i < minlength; i++) {
        if (strdata[i] < other.strdata[i]) {
            return true;
        }
        else if (strdata[i] > other.strdata[i]) {
            return false;
        }
    }
    return strlength < other.strlength;
}

bool mystring::operator<=(const mystring& other) const {
    int minLength = (strlength < other.strlength) ? strlength : other.strlength;
    for (int i = 0; i < minLength; ++i) {
        if (strdata[i] < other.strdata[i]) return true;
        if (strdata[i] > other.strdata[i]) return false;
    }
    return strlength <= other.strlength;
}



bool mystring::operator>(const mystring& other) const {
    int minLength = (strlength < other.strlength) ? strlength : other.strlength;
    for (int i = 0; i < minLength; ++i) {
        if (strdata[i] > other.strdata[i]) return true;
        if (strdata[i] < other.strdata[i]) return false;
    }
    return strlength > other.strlength;
}


bool mystring::operator>=(const mystring& other) const {
    int minLength = (strlength < other.strlength) ? strlength : other.strlength;
    for (int i = 0; i < minLength; ++i) {
        if (strdata[i] < other.strdata[i]) return false;
        if (strdata[i] > other.strdata[i]) return true;
    }
    return strlength >= other.strlength;
}


bool mystring::operator==(const mystring& other) const {
    if (strlength != other.strlength) {
        return false;
    }
    for (int i = 0; i < strlength; i++) {
        if (strdata[i] != other.strdata[i]) {
            return false;
        }
    }
    return true;
}

bool mystring::operator!=(const mystring& other) const {
    if (strlength != other.strlength) return true;

    for (int i = 0; i < strlength; ++i) {
        if (strdata[i] != other.strdata[i]) {
            return true;
        }

        return false;
    }
}
