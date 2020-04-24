#include <iostream>


using namespace std;

class Solution8
{
public:
    int myAtio(string s){
        int i=0,k=1;
        int rev=0;

        while (s[i]==' ')   ++i;

        if(s[i]=='+'||s[i]=='-'||(s[i]>='0'&&s[i]<='9'))  ;
        else   return 0;

        if(s.at(i)=='-') {   k=-1;   i++; }   
        if(s.at(i)=='-')  i++;
        if(i==s.size()-1) return 0;

        if (s.at(i)>='0'&&s.at(i)<='9')
        {
            for(int j=i;s[j]>='0'&&s[j]<='9'&&j<s.size();++j)
            {   
                int pop=s[j]-'0'; 

                if(k==1)    if(rev>INT32_MAX/10||(rev==INT32_MAX/10&&pop>7)) return INT32_MAX;
            
                if(k!=1)    if(rev>INT32_MAX/10||(rev==INT32_MIN/10&&pop>8)) return INT32_MIN;
   
                rev=rev*10+pop;          
            } 
            return rev*k;
        }
        else return 0;                 
    }
};

int main(){
    string s1,s2;

    cin>>s1;

    Solution8 s;

    cout<<s.myAtio(s1)<<endl;

    cin>>s2;
    cout<<s.myAtio(s2)<<endl;

    return 1;
}

