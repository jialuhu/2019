/*************************************************************************
	> File Name: Mystring.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  7/24 08:49:32 2019
 ************************************************************************/

#include<iostream>
#include <initializer_list>
static const size_t npos = -1;
class Mystring{
public:
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
    std::size_t size() const{return (_len);};
    const char* c_str() const{return _str;};

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
/*friend bool operator>=(const Mystring & lstr, const Mystring & rstr);
friend bool operator==(const Mystring &, const Mystring &);
friend bool operator!=(const Mystring &, const Mystring &);
friend bool operator<(const Mystring &, const Mystring &);
friend bool operator>(const Mystring &, const Mystring &);*/
int main()
{
    Mystring s0("Initial string");
    Mystring s1({'M','y','s','t','r','i','n','g'});
    Mystring s2(s0);
    Mystring s3(s0, 8, 3);
    Mystring s4("A character sequence");
    Mystring s5("Another character sequence", 12);
    Mystring s6(s5+s5);
    std::cout << "s0: " << s0 << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s4: " << s4 << std::endl;
    std::cout << "s5: " << s5 << std::endl;
    std::cout << "s6: " << s6 << std::endl;
    std::cout << "-----------------------"<< std::endl;
    Mystring st0,st1,st2,st3;
    st0 = "this is a test of mystring:";
    st1 = 'A';
    st2 = st0 + st1;
    std::cout << "st0: " << st0 << std::endl;
    std::cout << "st1: " << st1 << std::endl;
    std::cout << "st2: " << st2 << std::endl;
    std::cout << "---------------------- "<< std::endl;
    
    Mystring stl0,stl1;
    stl1 = "This";
    stl1 += 'H';
    std::cout << "stl0: " << stl1 << std::endl;
    std::cout << "stl0: " << stl1 << std::endl;
    std::cout << stl1.size() << std::endl;
    std::cout << stl1.c_str() << std::endl;

    std::cout << "---------------------- "<< std::endl;
    Mystring firstlevel ("com");
    Mystring secondlevel ("cplusplus");
    Mystring scheme ("http://");
    Mystring hostname;
    Mystring url;
    std::cout << scheme.size() << std::endl;
    std::cout << scheme.c_str() << std::endl;


    
    hostname = "www." + secondlevel + '.' + firstlevel;
    url = scheme + hostname;
    std::cout << "hostname: " << hostname << std::endl;
    std::cout << url << '\n';

    std::cout << "---------------------- "<< std::endl;
    std::cout << "firstlevel[0]: " << firstlevel[0] << std::endl; 
    secondlevel[1] = 'r';
    std::cout << "secondlevel[1]: " << secondlevel[1] << std::endl;
    std::cout << "---------------------- "<< std::endl;
 
    return 0;

}










