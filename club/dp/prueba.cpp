#include<bits/stdc++.h>
    using namespace std;
    #define MAX 100005
    long long dp[100005];
        long long count1[100005];
        int main(){
        int n,x;
        cin>>n;
        for(int i=0;i<n;i++){
            cin >> x;
            count1[x]++;
           // res=max(res,x);
        }
        dp[0]=0;
        dp[1]=count1[1];
        for(int i=2;i<MAX;i++){
            dp[i]=max(dp[i-1],dp[i-2]+i*count1[i]);
        }
        cout<<dp[MAX-1];
    }
