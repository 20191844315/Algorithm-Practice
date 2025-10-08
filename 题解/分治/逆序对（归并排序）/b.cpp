#include<iostream>
#include<vector>
using namespace std;

int mergesort(vector<int>&a,vector<int>&temp,int l,int r){ 
    //终止条件
    if(l>=r){
        return 0;
    }
    //递归划分
    int m=(l+r)/2;
    int res=mergesort(a,temp,l,m)+mergesort(a,temp,m+1,r);
    //合并子问题
    int i=l,j=m+1;
    for(int k=l;k<r+1;k++){//将数组中的内容备份
        temp[k]=a[k];
    }
    //开始归并
    for(int k=l;k<r+1;k++){
        if(i>m){
            a[k]=temp[j];
            j++;
        }else if(j>r){
            a[k]=temp[i];
            i++;
        }
        else if(temp[i]<temp[j]){
            a[k]=temp[i];
            i++;
            
        }else {
            a[k]=temp[j];
            j++;
            res+=m-i+1;
        }

       
    }
     return res;
}
int main(){
    int n;
    while(cin>>n){
        vector<int>a(n);
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<mergesort(a,temp,0,n-1)<<endl;

    }
    return 0;
}