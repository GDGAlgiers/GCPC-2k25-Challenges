#include<bits/stdc++.h>

using namespace std;

const int N=1000;
int n,a,b,x,y,ans;

int dp[N][N];

int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

int main(){
		memset(dp,0x3f,sizeof dp);
    scanf("%lld%lld%lld",&n,&a,&b);   
    
    for(int i=n;i>=1;i--){
        if(gcd(i,a)==1){
            x=i;break;
        }
    }
    for(int i=n;i>=1;i--){
        if(gcd(i,b)==1){
            y=i;break;
        }
    }
	    for(int i=1;i<=x;i++){
        ans+=gcd(i,a);
    }
    for(int i=1;i<=y;i++){
        ans+=gcd(i,b);
    }
 

	dp[1][1]=ans+(x-1)+(y-1);
	
	
 
	for (int i=x;i<=n;i++) {
		for (int j=y;j<=n;j++) {
			if (i==x&&j==y) continue;
			dp[i-x+1][j-y+1]=min(dp[i-x][j-y+1],dp[i-x+1][j-y])+gcd(i,a)+gcd(j, b);
		}
	}
    cout<<dp[n-x+1][n-y+1]<< endl;
    return 0;
}