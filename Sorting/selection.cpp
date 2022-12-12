#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void selection_sort(int a[],int n){
    int j,k;
    for(int i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(a[j]<a[k]){
                k=j;
            }
        }
        swap(&a[i],&a[k]);
    }
}
int main(){
    int n;
    cout<<"Enter Size: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter Array Elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Before Sorting: "<<endl;
    display(a,n);
    selection_sort(a,n);
    cout<<"After Sorting: "<<endl;
    display(a,n);
    return 0;
}