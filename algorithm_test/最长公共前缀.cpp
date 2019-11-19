//
// Created by Jialu  Hu on 2019-11-19.
//
/*编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }
        string pre = strs[0];
        for(int i=1; i<strs.size(); i++){
            int lastindex = strs[i].length()>pre.length()?pre.length():strs[i].length();
            for(int j=0; j<lastindex; j++){
                if(strs[i][j] != pre[j]){
                    lastindex = j;
                    break;
                }
            }
            pre = pre.substr(0,lastindex);
        }
        return pre;
    }
};


