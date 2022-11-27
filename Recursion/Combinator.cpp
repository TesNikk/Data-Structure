#include<iostream>
using namespace std;
int combinator(int n,int k){
    if(k==1){
        return n;
    }else if(n==k){
        return 1;
    }else{
        return combinator(n-1,k)+combinator(n-1,k-1);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<combinator(n,k);
    return 0;
}