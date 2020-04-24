#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//使用set
class Sol36{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
    unordered_map<size_t,unordered_set<char> > row_map,col_map,cel_map;
    for(auto i=0;i<board.size();++i)
    {
        for(auto j=0;j<board[0].size();++j)
        {
            int num=i/3*3+j;
            if(!(row_map[i].insert(board[i][j]).second
            &&col_map[j].insert(board[i][j]).second
            &&cel_map[num].insert(board[i][j]).second) ) return false;
        }
    }
    return true;
    }
};



//使用数组标记出现过的值
class Solution36{
public:
    bool ValidSudoku(vector<vector<char> >& board)
    {
        int usedrow[9][9]={0},usedcol[9][9]={0},usedblock[9][9]={0};
        for(auto i=0;i<board.size();++i)
        {
            for(auto j=0;j<board[0].size();++j)
            {
                if(board[i][j]!='.')
                {
                    int val=board[i][j]-'0'-1; //0-8 for 1-9
                    int blocknumber=i/3*3+j/3;
                    if(board[i][val]||board[j][val]||usedblock[blocknumber][val])
                        return false;
                    board[i][val]=board[j][val]=usedblock[blocknumber][val]=1;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution36 s;
    Sol36 s2;
    vector<vector<char> > brd1={
  {'8','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}};


  cout<<s.ValidSudoku(brd1)<<endl<<s2.isValidSudoku(brd1)<<endl;
  return 1;
}