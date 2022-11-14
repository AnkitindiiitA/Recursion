#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9+7;//M=1000000007
#define yes cout<<"YES\n";
#define no cout<<"NO\n";

void merge(vector<int>&v,int lo,int hi){

     int mid=lo+((hi-lo)>>1);

     int len1=mid-lo+1;
     int len2=hi-mid;

     //dynamic memory allocation
     int *first=new int[len1];
     int *second=new int[len2];

     int k=lo;
     for(int i=0;i<len1;i++){
          first[i]=v[k++];
     }
     k=mid+1;
     for(int i=0;i<len2;i++){
          second[i]=v[k++];
     }

     //merge

     int i=0;
     int j=0;
     k=lo;
     while(i<len1 && j<len2){
          if(first[i]<second[j]){
               v[k++]=first[i++];
          }else{
               v[k++]=second[j++];
          }
     }

     while(i<len1){
          v[k++]=first[i++];
     }

     while(j<len2){
          v[k++]=second[j++];
     }

     //important for space of dynamic memory allocation
     delete []first;
     delete []second;

}


void mergeSort(vector<int>&v,int lo,int hi){
     if(lo>=hi){
          return;
     }
     int mid=lo+((hi-lo)>>1);
     mergeSort(v,lo,mid);
     mergeSort(v,mid+1,hi);

     merge(v,lo,hi);

}


int32_t main(){

     int n;
     cin>>n;
     vector<int>v(n,0);
     for(int i=0;i<n;i++)cin>>v[i];

     int lo=0;
     int hi=n-1;
     mergeSort(v,lo,hi);

     for(int i=0;i<n;i++)cout<<v[i]<<" ";
     cout<<endl;

     

     return 0;
}

