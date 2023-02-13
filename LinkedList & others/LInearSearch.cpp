#include<iostream>
using namespace std;
int main(){
int a[50];
int n;
cout<<"Enter Size of the array: "<<endl;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
int x;
cout<<"ENter the elements you wanna search:"<<endl;
cin>>x;
int flag=0;
for(int i=0;i<n;i++)
{
    if(a[i]==x){
        flag=1;
        break;
    }
}
if(flag)
{
    cout<<"Found"<<endl;
}
else
{
    cout<<"Not found"<<endl;
}
    return 0;
}