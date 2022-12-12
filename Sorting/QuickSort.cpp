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
int partition(int a[],int l,int h){
    int pivot=a[l];
    int i=l;
    int j=h;
    do{
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j){
            swap(&a[i],&a[j]);
        }
    }while(i<j);
    swap(&a[l],&a[j]);
    return j;
}
void QuickSort(int a[],int l,int h){
    int j;
    if(l<h){
        j=partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}
int main(){
    int a[]={11,13,7,8,4,9,33,5,43,2,INT32_MAX};
    int n=10;
    cout<<"Before Sorting: "<<endl;
    display(a,n);
    QuickSort(a,0,n);
    cout<<"After Sorting: "<<endl;
    display(a,n);
    return 0;
}