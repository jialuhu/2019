/*************************************************************************
	> File Name: 最长回文字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/15 19:08:38 2019
 ************************************************************************/
/**
 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 
 示例 1：
 
 输入: "babad"
 输出: "bab"
 注意: "aba" 也是一个有效答案。
 示例 2：
 
 输入: "cbbd"
 输出: "bb"
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-palindromic-substring
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len==0){
            return "";
        }
        if(len==1){
            return s;
        }
        int start = 0;
        int max_l = 1;
        int dp[len][len]{0};
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<=i; j++){
                if(i-j<2){
                    dp[j][i] = (s[j]==s[i]);
                }else{
                    dp[j][i] = (s[j]==s[i] && dp[j+1][i-1]);
                }
                if(dp[j][i]&&max_l<(i-j+1)){
                    max_l = i-j+1;
                    start = j;
                }
            }
        }
        return s.substr(start,max_l);
    }
};
