#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9+7;//M=1000000007

int fact(int n,vector<int>&dp){
     if(n==0){
          return 1;
     }
     if(dp[n]!=-1){
          return dp[n];
     }

     dp[n]= (n*fact(n-1,dp))%M;
     return dp[n];
}

int32_t main(){

     int n;
     cin>>n;
     if(n<0){
          cout<<"Error\n";
          return 0;
     }
     vector<int>dp(n+1,-1);
     cout<<fact(n,dp)<<endl;

     return 0;
}

