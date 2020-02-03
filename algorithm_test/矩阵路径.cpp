/*************************************************************************
	> File Name: 矩阵路径.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  2/ 3 20:18:44 2020
 ************************************************************************/
/**
 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
 **/
class Solution {
public:
    bool isVisit(const char* matrix, int row, int col, const char *str,
                 int &length,bool* visited,int rows, int cols){
        if(str[length] == '\0'){
            return true;
        }
        bool hasPath = false;
        if(row>=0 && row<rows && col>=0 && col<cols &&
           matrix[row*cols+col]==str[length]&&visited[row*cols+col]==false){
            length++;
            visited[row*cols+col]=true;
            hasPath = isVisit(matrix,row,col+1,str,length,visited,rows,cols)||
            isVisit(matrix,row+1,col,str,length,visited,rows,cols)||
            isVisit(matrix,row,col-1,str,length,visited,rows,cols)||
            isVisit(matrix,row-1,col,str,length,visited,rows,cols);
            if(!hasPath){
                visited[row*cols+col] = false;
                length--;
            }
        }
        return hasPath;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        int length = 0;
        if(matrix==nullptr || rows<1 || cols<1 || str==nullptr){
            return false;
        }
        bool *visited = new bool[rows*cols];
        memset(visited,0,rows*cols);
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++){
                if(isVisit(matrix,i,j,str,length,visited,rows,cols)){
                    return true;
                }
            }
        }
        delete [] visited;
        return false;
    }
};
