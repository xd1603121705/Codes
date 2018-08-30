
#include "String.h"

// 通用构造函数，要先判断指针是否为空
String::String(const char* str) {
    if (str != nullptr) {
        length = strlen(str);
        m_str = new char[length + 1];
        strcpy(m_str, str);
    }
    else {
        length = 0;
        m_str = new char[1];
        *m_str = '\0';
    }
}

// 拷贝构造函数，要进行深复制
String::String(const String& other) {
    length = other.size();
    m_str = new char[length + 1];
    strcpy(m_str, other.c_str());
}

// 重载=
String& String::operator = (const String& other) {
    if (this == &other) {
        return *this;
    }
    delete [] m_str;
    length = other.size();
    m_str = new char[length +1];
    strcpy(m_str, other.c_str());
    return *this;
}

// 重载+
String String::operator + (const String& other) {
    String newString;
    newString.length = length + other.size();
    newString.m_str = new char[newString.length + 1];
    strcpy(newString.m_str, m_str);
    strcat(newString.m_str, other.c_str());
    return newString;
}

// 重载+=
String& String::operator += (const String &other) {
    length += other.size();
    char *newStr = new char[length + 1];
    strcpy(newStr, m_str);
    strcat(newStr, other.c_str());
    delete [] m_str;
    m_str = newStr;
    return *this;
}

// 获取长度
size_t String::size() const{
    return length;
}

// 获取字符串
const char* String::c_str() const{
    return m_str;
}

// 重载输入输出，返回is/os是为了实现形如cout << a << b的连续输出
std::istream& operator >> (std::istream &is, String &other) {
    char tmp[1000];
    is >> tmp;
    other.length = strlen(tmp);
    other.m_str = new char[other.length + 1];
    strcpy(other.m_str, tmp);
    return is;
}

std::ostream& operator << (std::ostream &os, const String &other) {
    os << other.m_str;
    return os;
}


