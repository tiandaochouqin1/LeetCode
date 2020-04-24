#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<int> Substring(string s,vector<string> &words)
    {
        unordered_map<string,int> counts;
        vector<int> indexs;
        for(auto word:words) counts[word]++;
        int n=s.length(),num=words.size(),len=words[0].size();
        for (size_t i = 0; i < n-num*len+1; i++)
        {
            unordered_map<string,int> seen;
            int j=0;
            for(;j<=num;++j)
            {
                string word=s.substr(i+j*len,len);
                if(counts.find(word)!=counts.end())
                {
                    seen[word]++;
                    if(seen[word]>counts[word]) break;
                }
                else break;
            }
            if(j==num) indexs.push_back(i);    
        }
        return indexs;
    }
};


int main()
{
    Solution s;
    string str{"barfoothefoobarman"};
    vector<string>  words{"foo","bar"};
    vector<int> index=s.Substring(str,words);
    for(auto in:index)
        cout<<in<<"  ";

    return 1;
}