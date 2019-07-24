/*************************************************************************
	> File Name: Mystring.h
	> Author: 
	> Mail: 
	> Created Time: 三  7/24 08:31:44 2019
 ************************************************************************/

#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <initializer_list>
class Mystring{
public:
    /*Mystring::Mystring构造*/
    Mystring():len(0),start(0),ends(0){
            _str = new char[1];
            _str[0]='\0';
            }
    
    Mystring(const Mystring& str);
    Mystring(const Mystring& str, size_t pos, size_t len = npos);
    Mystring(const char *s);
    Mystring(const char *s, size_t n);
    Mystring(initializer_list<char> il);
    template<class InputIterator>
        Mystring(InputIterator first, InputIterator last);
    Mystring(Mystring&& str) noexcept;

    Mystring& operator= (const Mystring& str);
    Mystring& operator= (const char *s);
    Mystring& operator= (char c);
    Mystring& operator= (initializer_list<char> il);
    Mystring& operator= (Mystring&& str) noexcept;
private:
    char *_str;
    size_t len;
    size_t start;
    size_t ends;
};

Mystring :: Mystring(const Mystring& str):len(str.len),start(str.start),ends(str.ends){
    _str = new char[len+1];
    std::swap(_str, str._str);
}


#endif
