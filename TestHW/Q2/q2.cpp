#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Sol{
public:
    string fru;
    int idx;
    int weight;
    Sol(string f,int i,int w){
        fru=f;
        idx=i;
        weight=w;
    }
}A[100];

int main(){
    map<string,map<int,int>> m;
    map<int,int> m2;
    int n,idx,w;
    string fru;
    cin>>n;
    for(int i=0;i<=n;++i){
        cin>>fru>>idx>>w;
        A[i]=Sol(fru,idx,w);
        // m2[idx]=w;
        // m[fru]=m2;
        cout<<A[i].fru<<A[i].idx<<A[i].weight<<endl;
    }
    
    

}