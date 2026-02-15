#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(int *arr, int s,int mid, int e)
{
     int n1=mid-s+1, n2=e-mid; 
     vector<int> leftArr(n1), rightArr(n2);
     for(int i=0; i<n1; i++)
     leftArr[i] = arr[s+i];
     for(int j=0; j<n2; j++)
     rightArr[j]=arr[mid+1+j];
     int left=0,right=0,k=s;
     while(left<n1 && right<n2)
     {
        if(leftArr[left]<=rightArr[right])
        {
            arr[k]=leftArr[left];
            left++;
        }
        else{
            arr[k]=rightArr[right];
            right++;
        }
        k++;
     }
        while(left < n1) {
        arr[k] = leftArr[left];
        left++;
        k++;
    }
    while(right < n2) {
        arr[k] = rightArr[right];
        right++;
        k++;
    }
}
void mergeSort(int *arr,int s,int e)
{
    if(s>=e)
    return;
    int mid=s+(e-s)/2;
    //left part sort karna hai
    mergeSort(arr,s,mid);
    //right part sort karna hai
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}
int main()
{
    int arr[10] = {3,1,6,77,89,100,22,4,51,777};
    int n=10;
    mergeSort(arr,0,n-1);
    for(int num: arr)
    cout<<num<<" ";
    cout<<'\n';
    return 0;
}