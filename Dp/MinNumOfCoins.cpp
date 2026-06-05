#include<bits/stdc++.h>
using namespace std;
int COIN_CHANGE(int coins[],int n,int target){
     int dp[n+1][target+1];
     for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
     for(int j=1;j<=target;j++){
        dp[0][j]=INT_MAX-1;
      }
    for(int i=1;i<=n;i++){
    for(int j=1;j<=target;j++){
       if (coins[i-1] <= j){
          dp[i][j] = min (dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
       }
       else{
  dp[i][j] = dp[i-1][j];
    }
  }
 }
 if (dp[n][target] == INT_MAX-1){
return -1;
 }
 else{
return dp[n][target];
 }
}
int main(){
     int n;
     int target;
     cout<< "enter num of coins:";
     cin>> n;
     cout<<"enter amount:";
     cin>>target;
     int coins[n];
     for(int i=0;i<n;i++){
        cin>>coins[i];
     }

   int min_num = COIN_CHANGE(coins, n, target);
   if(min_num == -1){
    cout<< "No solution";
   }
   else{
cout<<"Minimum Number:" <<min_num <<endl;
   }
}

