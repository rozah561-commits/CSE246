#include<bits/stdc++.h>
using namespace std;
int COIN_CHANGE_WAYS(int coins[], int n, int target){
int dp [n+1][target+1];

for(int i=0;i<=n;i++){
        dp[i][0]=1;
}
for(int j=1;j<=target;j++){
        dp[0][j]=0;
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=target;j++){
       if (coins[i-1] <= j){
          dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];     //uporer copy +
       }
   else{
  dp[i][j] = dp[i-1][j];       //uporer ta copy
    }
  }
 }
 return dp[n][target];
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

   int total_ways = COIN_CHANGE_WAYS(coins, n, target);

cout<<"Number of ways:" <<total_ways <<endl;
}


