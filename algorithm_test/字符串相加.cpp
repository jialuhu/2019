/*************************************************************************
	> File Name: 字符串相加.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/22 08:53:48 2019
 ************************************************************************/
/**
 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 
 注意：
 
 num1 和num2 的长度都小于 5100.
 num1 和num2 都只包含数字 0-9.
 num1 和num2 都不包含任何前导零。
 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/add-strings
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int p1 = len1-1;
        int p2 = len2-1;
        int c = 0;
        int sum = 0;
        string result("");
        while(p1>=0 || p2>=0){
            sum = 0;
            if(p1>=0){
                sum = sum + num1[p1--] - '0';
            }
            if(p2>=0){
                sum = sum + num2[p2--] - '0';
            }
            sum = sum + c;
            c = sum/10;
            result += to_string(sum%10);
        }
        if(c==1){
            result += to_string(c);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
