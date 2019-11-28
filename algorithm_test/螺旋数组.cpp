/*************************************************************************
	> File Name: 螺旋数组.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 11/28 20:07:19 2019
 ************************************************************************/
/**
 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 
 示例 1:
 
 输入:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 输出: [1,2,3,6,9,8,7,4,5]
 示例 2:
 
 输入:
 [
 [1, 2, 3, 4],
 [5, 6, 7, 8],
 [9,10,11,12]
 ]
 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/spiral-matrix
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
1、向右边移动，移动结束，将这一行删除，使得上边界发生变化
2、更新上边界
3、向下移动，移动结束，将右边列删除，使得右边界发生变化
4、更新右边界
5、向左移动，移动结束，将下边界的行删除，使得下边界发生变化
6、更新下边界
7、向上移动，移动结束，将左边列删除，使得做边界发生变化
8、更新左边界
终止条件为：上下边界有相交、左右边界有相交
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0) return result;
        int right = matrix[0].size()-1;
        int left = 0;
        int up = 0;
        int down = matrix.size()-1;
        while(true){
            for(int i=left; i<=right; i++) result.push_back(matrix[up][i]);
            if(++up > down) break;
            for(int i=up; i<=down; i++) result.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i=right; i>=left; i--) result.push_back(matrix[down][i]);
            if(--down < up) break;
            for(int i=down; i>=up; i--) result.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return result;
    }
};
