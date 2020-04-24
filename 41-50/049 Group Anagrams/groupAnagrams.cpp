#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs)
            mp[strSort(s)].push_back(s);
        vector<vector<string>> anagrams;
        for(auto p:mp)
            anagrams.push_back(p.second);
        return anagrams;
        
    }

private:
    string strSort(string s){
        int count[26]={0};
        for(char c:s)
            count[c-'0']++;
        string t;
        for(int i=0;i<26;i++) 
            t+=string(count[i],i+'a');
        return t;
    }
};

int main(){
    Solution49 s;
    
}