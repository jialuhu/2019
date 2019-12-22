/*************************************************************************
	> File Name: 字符串揭码.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/22 10:57:51 2019
 ************************************************************************/
/**
 给定一个经过编码的字符串，返回它解码后的字符串。
 
 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 
 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 
 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 
 示例:
 
 s = "3[a]2[bc]", 返回 "aaabcbc".
 s = "3[a2[c]]", 返回 "accaccacc".
 s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/decode-string
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
class Solution {
public:
    string decodeString(string s) {
        stack<int> stack_n;
        stack<string> stack_s;
        int len = s.size();
        int num=0;
        string curr("");
        for(int i=0; i<len; i++){
            if(s[i]>='0' && s[i]<='9'){
                num = num*10 + s[i]-'0';
            }
            else if(s[i] == '['){
                stack_n.push(num);
                stack_s.push(curr);
                num = 0;
                curr.clear();
            }
            else if(s[i] == ']'){
                int n = stack_n.top();
                string res = stack_s.top();
                for(int i=0; i<n; i++){
                    res = res+curr;
                }
                curr = res;
                stack_s.pop();
                stack_n.pop();
            }
            else{
                curr = curr+s[i];
            }
        }
        return curr;
    }
};

