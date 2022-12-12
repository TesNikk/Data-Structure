#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void merge(int a[],int l,int mid,int h){
    int i=l;
    int k=l;
    int j=mid+1;
    int b[h+1];
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }else{
            b[k++]=a[j++];
        }
    }
    for(;i<=mid;i++){
        b[k++]=a[i];
    }
    for(;j<=h;j++){
        b[k++]=a[j];
    }
    for(i=l;i<=h;i++){
        a[i]=b[i];
    }
}
void mergesort(int a[],int l,int h){
    if(l<h){
    int mid=(l+h)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,h);
    merge(a,l,mid,h);
    }
}
int main(){
    int a[]={5,6,1,2,3,4,9,10};
    int n=8;
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}