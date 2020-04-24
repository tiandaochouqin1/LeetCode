#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    map<string,int> m;
    map<string,int>::iterator iter,iter2;
    string is;
    int count=0;
    while(getline(cin,is)){
        if(is=="")
           break;
        string s="";
        char sn;
        int num;
        int flag=INT32_MAX;
        for(int i=0;i!=is.size();++i){
            if(is[i]==','){
                flag=i;
                //cout<<i<<"h"<<is.size()<<endl;   

                if(is.size()-flag<=2){
                    sn=is[i+1];
                    num=sn-'0';
                  //  cout<<sn<<endl<<num<<endl;
                    }
                else {
                    num=10;
                    break;
                    }
            }                         
            if(i<flag)
                s+=is[i];
          
        }      
        iter=m.find(s);
        if(iter==m.end())
            m[s]=num;
        else
            m[s]+=num;
       // cout<<s<<" 111 "<<num;
        s.clear();  
    }
    //cout<<m.size()<<endl;
    for(iter2=m.begin();iter2!=m.end();iter2++){
       // cout<<iter2->first<<" - "<<iter2->second<<endl;
        if(iter2->second>=10)
            count++;
    }
    cout<<count<<endl;
    return 0;
}