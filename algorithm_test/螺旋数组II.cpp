/*************************************************************************
	> File Name: 螺旋数组II.cpp
	> Author: 
	> Mail: 
	> Created Time: 五 12/20 21:06:18 2019
 ************************************************************************/

/**
 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 
 示例:
 
 输入: 3
 输出:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/spiral-matrix-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        int up = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int count = 1;
        while(true){
            for(int i=left; i<=right; i++) result[up][i] = count++;
            if(++up > down) break;
            for(int i=up; i<=down; i++) result[i][right] = count++;
            if(--right < left) break;
            for(int i=right; i>=left; i--) result[down][i] = count++;
            if(--down < up) break;
            for(int i=down; i>=up; i--) result[i][left] = count++;
            if(++left > right) break;
        }
        return result;
    }
};
