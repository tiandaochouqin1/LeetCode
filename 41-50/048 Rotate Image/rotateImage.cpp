#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution48{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int row=matrix.size(),col=matrix[0].size();
        for(int i=0;i<row;++i)
            for(int j=0;j<col-i;++j)
            {
                swap(matrix[i][j],matrix[col-j-1][row-i-1]);
            }
        //reverse函数代替  
        //for(int i=0;i<row/2;++i)
        //     for(int j=0;j<col;++j)
        //     {
        //         swap(matrix[i][j],matrix[row-i-1][j]);
        //     }
        reverse(matrix.begin(),matrix.end());
        
    }
    void print(vector<vector<int>> v)
    {
    for(auto &i:v)
        {for(auto j:i)
            cout<<j<<',';
        cout<<endl;
        }
    }
};

int main(){
    Solution48 s;
    vector<vector<int>> a1{{1,2,3},{4,5,6},{7,8,9}},a2{{5,1,9,11},{2,3,8,10},{13,3,6,7},{15,14,12,16}};
    s.rotate(a1),s.rotate(a2); 
    s.print(a1),s.print(a2);
    
    return 1;
}