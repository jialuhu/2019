/*************************************************************************
	> File Name: Mystring.h
	> Author: 
	> Mail: 
	> Created Time: 三  7/24 08:31:44 2019
 ************************************************************************/

#ifndef _MYSTRING_H
#define _MYSTRING_H
#include<iostream>
#include<iterator>
#include <initializer_list>
static const size_t npos = -1;
class Mystring;
class MyIterator : public std::iterator<std::input_iterator_tag, Mystring>{
public:
    MyIterator(char* p){
        _ptr = p;
    }
    //赋值
    MyIterator& operator = (const MyIterator &iter)
    {
        _ptr = iter._ptr;
    }
    //不等于
    bool operator != (const MyIterator &iter)
    {
        return _ptr!= iter._ptr;
    }
    //等于
    bool operator == (const MyIterator &iter)
    {
        return _ptr == iter._ptr;
    }
    //前缀自加
    MyIterator& operator ++ ()
    {
        _ptr++;
        return *this;
    }
    //后缀自加
    MyIterator operator ++ (int)
    {
        MyIterator tmp= *this;
        _ptr++;
        return tmp;
    }
    //取值
    char operator * ()
    {
        return *_ptr;
    }
    
private:
    char* _ptr;//实际的内容指针，通过该指针跟容器连接
};

class Mystring{
public:
    typedef MyIterator iterator;
    /*Mystring::Mystring构造*/
    Mystring():_len(0),_start(0),_ends(0){
        _str = new char[1];
        _str[0]='\0';
    }
    
    Mystring(const Mystring& str);
    Mystring(const Mystring& str, size_t pos, size_t _len = npos);
    Mystring(const char *s);
    Mystring(const char *s, size_t n);
    Mystring(std::initializer_list<char> il);
    Mystring(Mystring&& str);
    
    
    /*重载=*/
    Mystring& operator= (const char *s);
    Mystring& operator= (const Mystring& str);
    Mystring& operator= (char c);
    Mystring& operator= (std::initializer_list<char> il);
    Mystring& operator= (Mystring&& str);
    
    /*重载+=*/
    Mystring& operator+=(const char *s);
    Mystring& operator+=(const Mystring& str);
    Mystring& operator+=(char c);
    
    
    /*重载[]*/
    char & operator[](size_t pos);
    const char& operator[](size_t pos) const;
    
    /*部分功能方法*/
    size_t size() const{return (_len);}
    const char* c_str() const{return _str;};
    size_t compare(const Mystring &str){return strcmp(_str, str._str);}
    char& front(){return _str[_start];}
    const char& front() const{return _str[_start];}
    
    char& back(){
        if((std::strcmp(_str," "))!=0)
        {
            return _str[_ends];
        }
    }
    
    const char& back() const {
        if((std::strcmp(_str," "))!=0)
            return _str[_ends];
    }
    
    char& at (size_t pos){
        if(pos<0 || pos >= _len)
        {
            /*抛出异常未写*/
            exit(1);
        }
        return _str[pos];
    }
    
    const char& at (size_t pos) const{
        if(pos<0 || pos >= _len){
            /*抛出异常*/
            exit(1);
        }
        return _str[pos];
    }
    
    bool empty() const{
        return (_start==_ends==0)?true:false;
    }
    
    void clear(){
        _str[0]='\0';
        _ends = 0;
        _len = 0;
        _start = 0;
    }
    
    Mystring& push_back (char c){
        *this = *this + c;
        return *this;
    }
    
    /*此处实现与源码的原理天差地别*/
    Mystring& append (const Mystring& str){
        *this = *this + str;
        return *this;
    }
    
    Mystring& append (const char* s){
        *this = *this+s;
        return *this;
    }
    
    iterator begin(){
        return iterator(_str);
    }
    iterator end(){
        return iterator(_str + _len);
    }
    
    /*重载<=*/
    friend bool operator<=(const Mystring & lstr, const Mystring & rstr);
    friend bool operator>=(const Mystring & lstr, const Mystring & rstr);
    friend bool operator==(const Mystring &, const Mystring &);
    friend bool operator!=(const Mystring &, const Mystring &);
    friend bool operator<(const Mystring &, const Mystring &);
    friend bool operator>(const Mystring &, const Mystring &);
    
    friend Mystring operator+(const Mystring & lhs, const Mystring & rhs);
    friend Mystring operator+(const Mystring & lhs, const char *s);
    friend Mystring operator+(const char *s, const Mystring & lhs);
    friend Mystring operator+(const Mystring & lhs, const char ch);
    friend Mystring operator+(const char ch, const Mystring &lhs);
    friend std::ostream & operator<<(std::ostream &os, const Mystring& str);
    friend std::istream & operator>>(std::istream &is, Mystring& str);
    
    
    ~Mystring(){
        delete [] _str;
    }
private:
    char *_str;
    size_t _len;
    size_t _start;
    size_t _ends;
};

Mystring :: Mystring(const Mystring& str)
:_len(str._len),_start(str._start),
_ends(str._ends){
    _str = new char[_len+1];
    std::strcpy(_str, str._str);
}

Mystring :: Mystring(const Mystring& str, size_t pos,
                     size_t _len){
    try{
        if(pos >= str._len)
        {
            throw "Out of Range errno.";
        }
    }catch(const char *er){
        std::cout << er << std::endl;
        delete [] str._str;
        exit(1);
    }
    this->_len = _len;
    _start = 0;
    _ends = _len-1;
    _str = new char[_len+1];
    for(int i=pos; i<(pos+_len); i++)
    {
        _str[_start++] = str._str[i];
    }
    _str[_len] = '\0';
    
}

Mystring :: Mystring(const char *str)
{
    int length = std::strlen(str);
    _str = new char[length+1];
    _len = length;
    _start = 0;
    _ends = length-2;
    std::strncpy(_str, str, length);
    _str[length] = '\0';
}

Mystring :: Mystring(const char *str, size_t n)
:_ends(n-1),_start(0){
    _str = new char[n];
    _len = n;
    std::strncpy(_str, str, n);
}

Mystring :: Mystring(std::initializer_list<char> il)
{
    _len = il.size();
    _str = new char[_len];
    _start = 0;
    _ends = _len-1;
    for(auto it = il.begin(); it != il.end(); it++){
        _str[_start++] = *it;
    }
    _start = 0;
}

Mystring :: Mystring(Mystring&& str):_len(str._len),
_start(str._start), _ends(str._ends){
    _str = str._str;
    str._str = nullptr;
    str._len = 0;
    str._start = 0;
    str._ends = 0;
}

Mystring& Mystring :: operator=(const char *str)
{
    delete [] _str;
    int len = std::strlen(str);
    _str = new char [len+1];
    std::strcpy(_str, str);
    _start = 0;
    _ends = len;
    _len = len;
    return *this;
}

Mystring& Mystring :: operator=(const Mystring &str)
{
    delete [] _str;
    _len = std::strlen(str._str);
    _str = new char [_len+1];
    _start = str._start;
    _ends = _len-1;
    std::strcpy(_str, str._str);
    return *this;
}

Mystring& Mystring :: operator=(const char ch)
{
    delete [] _str;
    _len = 1;
    _str = new char[2];
    _start = 0;
    _ends = 0;
    _str[0] = ch;
    return *this;
}

Mystring& Mystring :: operator=(std::initializer_list<char> il)
{
    _len = il.size();
    _str = new char[_len+1];
    _start = 0;
    _ends = _len-1;
    for(auto it=il.begin(); it!=il.end(); it++)
    {
        _str[_start++] = *it;
    }
    _start = 0;
    return *this;
}

Mystring& Mystring :: operator=(Mystring&& str)
{
    if(this == &str) return *this;
    delete [] _str;
    _len = str._len;
    _start = str._start;
    _ends = str._ends;
    _str = str._str;
    str._str = nullptr;
    str._ends = 0;
    str._len = 0;
    return *this;
}

Mystring& Mystring :: operator+=(const char *s)
{
    *this = *this + s;
    return *this;
}

Mystring& Mystring :: operator+=(const Mystring& str){
    *this = *this + str;
    return *this;
}

Mystring& Mystring :: operator+=(char c){
    *this = *this + c;
    return *this;
}

char & Mystring :: operator[](size_t pos)
{
    if(pos <= _ends) return _str[pos];
    else return _str[0];
}

const char & Mystring :: operator[] (size_t pos)const
{
    if(pos <= _ends) return _str[pos];
    else return _str[0];
}

std::ostream & operator<<(std::ostream &os, const Mystring& str)
{
    os << str._str;
    return os;
}

std::istream & operator>>(std::istream &is, Mystring& str)
{
    char tem[1024];
    is.get(tem, 1024);
    if(is){
        str=tem;
    }
    while(is && is.get() != '\n')
        continue;
    return is;
}

Mystring operator+(const Mystring& lhs, const Mystring& rhs)
{
    int l_len = std::strlen(lhs._str);
    int r_len = std::strlen(rhs._str);
    char *temp;
    temp = new char[lhs._ends+rhs._ends+1];
    std::sprintf(temp,"%s",lhs._str);
    std::sprintf(temp,"%s%s",temp,rhs._str);
    temp[strlen(temp)] = '\0';
    Mystring result(temp);
    delete [] temp;
    return result;
}
Mystring operator+(const Mystring& lhs, const char *s)
{
    std::cout << lhs._str << " " << s << std::endl;
    int l_len = std::strlen(lhs._str);
    int s_len = std::strlen(s);
    char *temp;
    temp = new char[l_len+s_len+1];
    std::strncpy(temp, lhs._str, l_len);
    std::strcat(temp,s);
    Mystring result(temp);
    delete [] temp;
    return result;
}

Mystring operator+(const char *s, const Mystring& lhs)
{
    Mystring temp(s);
    return temp+lhs;
}

Mystring operator+(const Mystring & lhs, const char ch){
    std::cout << lhs._str << std::endl;
    char *temp;
    int l_len = strlen(lhs._str);
    temp = new char [l_len+1];
    std::strncpy(temp,lhs._str,l_len);
    temp[l_len] = ch;
    temp[l_len+1] = '\0';
    Mystring result(temp);
    delete [] temp;
    return result;
}

Mystring operator+(const char ch, const Mystring & lhs){
    Mystring temp;
    temp = ch;
    return temp+lhs;
}

bool operator<=(const Mystring & lstr, const Mystring & rstr){
    return (std::strcmp(lstr._str,rstr._str)<=0?false:true);
}
bool operator>=(const Mystring & lstr, const Mystring & rstr){
    return (std::strcmp(lstr._str,rstr._str)<=0?true:false);
}

bool operator==(const Mystring & lstr, const Mystring & rstr){
    return (std::strcmp(lstr._str,rstr._str)==0?true:false);
}
bool operator!=(const Mystring & lstr, const Mystring & rstr){
    return (std::strcmp(lstr._str,rstr._str)==0?false:true);
}

#endif
