/*************************************************************************
	> File Name: 找不同.cpp
	> Author: 
	> Mail: 
	> Created Time: 一 12/ 9 22:43:34 2019
 ************************************************************************/
/**
 给定两个字符串 s 和 t，它们只包含小写字母。
 
 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 
 请找出在 t 中被添加的字母。
 
 
 
 示例:
 
 输入：
 s = "abcd"
 t = "abcde"
 
 输出：
 e
 
 解释：
 'e' 是那个被添加的字母。
 提交次数：6
 提交结果：提交通过
 通过测试用例：54/54
 语言：cpp
 执行用时：8 ms
 消耗内存：9 MB
 

 **/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int map1[28]={0};
        int map2[28]={0};
        int len1 = s.size();
        char ch=0;
        for(int i=0; i<len1; i++)
        {
            int pos = (int)s[i];
            map1[pos-97]++;
        }
        for(int i=0; i<len1+1; i++){
            int pos = (int)t[i];
            map2[pos-97]++;
        }
        for(int i=0; i<26; i++){
            if(map1[i]!=map2[i]){
                ch = (char)(i+97);
                return ch;
            }
        }
        return ch;
        
        
    }
};
