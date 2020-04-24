#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    int sum=0;
    vector<int> v;
    while(cin>>n){
        sum+=n;
        if(cin.get()=='\n'){
            v.emplace_back(sum);
            sum=0;
        }
    }
    for(auto i:v)
        cout<<i<<endl;
    return 0;
}