#include<bits/stdc++.h>
using namespace std;
int count_Distinct_LCS(string X,string Y)
{
    int n=X.size();
    int m=Y.size();
    int dp[n+1][m+1];
    int c[n+1][m+1];
    for(int i=0; i<=n; i++)
    {
        dp[i][0]=0;
        c[i][0]=1;
    }
    for(int j=0; j<=m; j++)
    {
        dp[0][j]=0;
        c[0][j]=1;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(X[i-1]==Y[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                c[i][j]=c[i-1][j-1];
            }
            else
            {

                if(dp[i-1][j] > dp[i][j-1])
                {
                    dp[i][j] = dp[i-1][j];
                    c[i][j] = c[i-1][j];
                }
                else if(dp[i-1][j] < dp[i][j-1])
                {
                    dp[i][j] = dp[i][j-1];
                    c[i][j] = c[i][j-1];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                    c[i][j] = c[i-1][j] + c[i][j-1];

                    if(dp[i-1][j-1] == dp[i][j])
                        c[i][j] -= c[i-1][j-1];
                }
            }
        }


    }return c[n][m];
}
int main(){

string X,Y;
cin>>X>>Y;
int Count=count_Distinct_LCS( X, Y);
cout<<"Ans :"<<Count<<endl;
return 0;

}
