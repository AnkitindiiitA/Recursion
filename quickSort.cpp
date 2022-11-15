#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9+7;//M=1000000007
#define yes cout<<"YES\n";
#define no cout<<"NO\n";

int partition(vector<int>&v,int lo,int hi){
     int cnt=0;
     int pivot = v[lo];
     for(int i=lo+1;i<=hi;i++){
          if(v[i]<=v[lo])cnt++;
     }

     int pivotIndex = lo + cnt;

     swap(v[lo],v[pivotIndex]);

     int i=lo;
     int j=hi;
     while(i<pivotIndex && j>pivotIndex){
          while(v[i]<=pivot){
               i++;
          }
          while(v[j]>pivot){
               j--;
          }

          if(i<pivotIndex && j>pivotIndex){
               swap(v[i++],v[j--]);
          }
     }




     return pivotIndex;

}

void quickSort(vector<int>&v,int lo,int hi){
     if(lo>=hi){
          return;
     }

     int index = partition(v,lo,hi);

     quickSort(v,lo,index-1);
     quickSort(v,index+1,hi);


}
    


int32_t main(){

     int n;
     cin>>n;
     vector<int>v(n,0);
     for(int i=0;i<n;i++)cin>>v[i];

     quickSort(v,0,n-1);

     for(int i=0;i<n;i++)cout<<v[i]<<" ";
     cout<<endl;
     

     return 0;
}

//H/W = is it in-place sorting technique?
// is it a stable algorithm?
