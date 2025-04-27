
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n , a, b;
        cin>>n>>a>>b;
        int g = gcd(a,b);
        vector<int> vec(n);
        for(int i=0; i<n;i++){
            cin>>vec[i];
            vec[i]%=g;
        }
        sort(vec.begin(),vec.end());
        int res= vec[n-1]-vec[0];
        for(int i=1; i<n;i++){
           res=min(res,vec[i-1]+g-vec[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}