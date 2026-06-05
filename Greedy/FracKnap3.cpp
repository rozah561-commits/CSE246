#include <bits/stdc++.h>
using namespace std;
void sortByRatioDescending(int n,double benefit[], double weight[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){

              if (benefit[j] < benefit[j + 1]) {

                double temp1=benefit[j];
                benefit[j]=benefit[j+1];
                benefit[j+1]=temp1;

               double temp2=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp2;
            }
        }
    }
}
double FractionalKnapsack(int n, double benefit[],double weight[], double capacity){
double totalProfit = 0.0;
   for(int i=0;i<n;i++){
    if(weight[i]<=capacity){
        capacity = capacity - weight[i];
        totalProfit = totalProfit + benefit[i]* weight[i];
    }else{
       totalProfit = totalProfit + (benefit[i] *weight[i] )*(capacity / weight[i]);
       break;
    }
   }
   return totalProfit;
}
int main(){
int n;
double capacity;
cin>> n >> capacity;
double benefit[n];
double weight[n];
for(int i=0;i<n;i++){
        cin>>benefit[i];
}
for(int i=0;i<n;i++){
        cin>>weight[i];
}
sortByRatioDescending(n,benefit,weight);
double result = FractionalKnapsack(n,benefit,weight,capacity);
cout<< result << endl;
}
