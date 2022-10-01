#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int l,int h){
    int pivot=a[l];
    int i=l;
    int j=h;
    while(i<j){
        while(a[i]<=pivot)
        i++;
        while(a[j]>pivot)
        j--;
        if(i<j)
        swap(&a[i],&a[j]);
    }
    swap(&a[j],&a[l]);
    return j;
}
void quicksort(int a[],int l, int h){
    if(l<h){
        int pivot = partition(a,l,h);
        quicksort(a,l,pivot-1);
        quicksort(a,pivot+1,h);
    }
}

int main () {
    int a[]={4,6,2,5,7,9,1,3};
    int a_size=sizeof(a)/sizeof(a[0]);
    int h=a_size-1;
    quicksort(a,0,h);
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<a_size;i++)
    cout<<a[i]<<" ";
    return 0;
}