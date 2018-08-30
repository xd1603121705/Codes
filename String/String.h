
/*
 *    Datatime: 2018/08/30-18:09
 *    filename: String.cpp
 * Description: 自己实现String类
 *
 * */
#include <stdlib.h>
#include <string.h>
#include <iostream>

class String
{
    public:
        String() = default;                  // 默认构造函数
        String(const char* str);   	     // 普通构造函数
        String(const String& other);         // 拷贝构造函数

        // 析构函数，对于普通类型的数组，delete和delete[]没区别，但是对于类对象，delete
        // 会造成内存泄露
        ~String() {
            delete []m_str;
            length = 0;
        }

        String& operator =  (const String &other);     // 重载=
        String  operator +  (const String &other);     // 重载+
        String& operator += (const String &other);     // 重载+=

        bool operator == (const String &other) const {  // 重载==
            if (length != other.size()) {
                return false;
            }
            return (strcmp(m_str, other.c_str()) == 0) ? true : false;
        }

        char& operator [](int n) const;                // 重载[]


        size_t size() const;                 // 获取长度
        const char* c_str() const;           // 获取C字符串

        friend std::istream& operator >> (std::istream &is, String &other); // 输入
        friend std::ostream& operator << (std::ostream &os, const String &other); // 输出


    private:
        char *m_str;
        size_t length;
};

