#include <vector>
#include <iostream>
using namespace std;

class Solution37{

    int row[9][10]={0},col[9][10]={0},cel[3][3][10]={0};

public:
    void SolveSudoku(vector<vector<char> >&board)
    {
        
        for(auto r=0;r<9;++r)
        {
            for(auto c=0;c<9;++c)
            {
                if(board[r][c]!='.')
                {
                    int val=board[r][c];
                    row[r][val]=1,col[c][val]=1,cel[r/3][c/3][val]=1;
                }
            }
        }
        dfs(board,0,0);
    }

    bool check(int r,int c,char val)
    {
        int vv=val-'0';
        // cout<<r<<'d'<<c<<'d'<<val<<';';
        if(row[r][vv]||col[c][vv]||cel[r/3][c/3][vv]) return false;
        cout<<"true"<<r<<'d'<<c<<'d'<<val<<';';
        return true;
    }
//深度优先搜索
//沿着树的深度遍历树的节点，尽可能深地搜索树的分支；当节点所在边都已被探寻过，搜索将回溯
    bool dfs(vector<vector<char> >& board,int r ,int c )
    {
        if(r==9) return  true;
        if(c==9) return dfs(board,r+1,0);//行与列的移动
// cout<<r<<'F'<<c<<endl;
    
        if(board[r][c]!='.') return dfs(board,r,c+1);//跳过已知值
cout<<r<<'-'<<c<<endl;


        for(char ch:{'1', '2', '3', '4', '5', '6', '7', '8', '9'})
        {
            if(check(r,c,ch))
            {   cout<<r<<'M'<<c<<endl;

                board[r][c]=c;
                int cn=ch-'0';
                row[r][cn]=1,col[c][cn]=1,cel[r/3][c/3][cn]=1;
                if(dfs(board,r,c+1)) 
                {cout<<r<<'.'<<c<<endl;
                    return true;}//此处不断向下搜索，并且回溯。 函数在此处返回true
                row[r][cn]=0,col[c][cn]=0,cel[r/3][c/3][cn]=0;//此次尝试失败，回滚
                board[r][c]='.';
            }
        }
        return false;
    }
};

int main(){
    Solution37 s;
    vector<vector<char>> brd={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}

    };
    s.SolveSudoku(brd);

    cout<<"fsdfs";
    for(const auto &v:brd)
    {
        for(auto c:v)
            cout<<c<<",";
        cout<<endl;
    }
    return 1;
}