/*************************************************************************
	> File Name: 替换空格.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  1/31 21:02:05 2020
 ************************************************************************/
/**
 
 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 **/
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int count = 0;
        char* p = str;
        while(p[0]!='\0'){
            if(p[0]==' '){
                count++;
            }
            p++;
        }
        int newlength = length+count*2;
        int len = newlength;
        while(length>=0 && length<len){
            if(str[length]!=' '){
                str[len--] = str[length];
                length--;
            }else if(str[length]==' '){
                str[len--] = '0';
                str[len--] = '2';
                str[len--] = '%';
                length--;
            }
        }
    }
};
