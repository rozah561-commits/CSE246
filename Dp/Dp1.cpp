#include<bits/stdc++.h>
using namespace std;
long long Num_Ways(int coins[],int n, int amount ,int k){

 long long dp[n+1][amount+1][k+1];
 for(int i=0;i<=n;i++){
    for(int j=0;j<=amount;j++){
        for(int K=0;K<=k;K++){
            dp[i][j][K]=0;
        }
    }
 }
    for (int i = 0; i <= n; i++){
         dp[i][0][0] = 1;
    }
     for(int i=1;i<=n;i++){
        for(int j=0;j<=amount;j++){
            for(int K=0;K<=k;K++){
                dp[i][j][K]=dp[i-1][j][K];
                if(coins[i-1]<=j&&K>0){
                     dp[i][j][K]+=dp[i][j-coins[i-1]][K-1];
                }
            }
        }
     }
     return dp[n][amount][k];
}
int main(){
int n,amount,k;
cout<<"Enter num of coins:";
cin>>n;
cout<<"Enter amount:";
cin>>amount;
cout<<"Enter exact num of coins (k) :";
cin>>k;
int coins[n];
cout<<"Enter coins :";
for (int i = 0; i < n; i++){
    cin>>coins[i];
}
long long ways=Num_Ways(coins, n,amount,k);
cout<<"Num of ways: "<<ways<<endl;
return 0;
}
