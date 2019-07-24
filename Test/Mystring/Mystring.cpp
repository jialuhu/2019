/*************************************************************************
	> File Name: Mystring.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  7/24 08:49:32 2019
 ************************************************************************/

#include<iostream>
#include"Mystring.hpp"

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
    std::cout << "back: "<<scheme.back() << std::endl;
    

    
    hostname = "www." + secondlevel + '.' + firstlevel;
    url = scheme + hostname;
    std::cout << url << '\n';

    std::cout << "---------------------- "<< std::endl;
    std::cout << "firstlevel[0]: " << firstlevel[0] << std::endl; 
    secondlevel[1] = 'r';
    std::cout << "secondlevel[1]: " << secondlevel[1] << std::endl;
    std::cout << "---------------------- "<< std::endl;
    firstlevel.clear();
    firstlevel = "hujialu";
    std::cout << firstlevel << std::endl;
    firstlevel.push_back('X');
    std::cout << "---------------------- "<< std::endl;
    auto it = firstlevel.begin();
    for(it; it!=firstlevel.end(); it++)
    {
    std::cout << *it;
    }
    std::cout << std::endl;
    
    return 0;

}










