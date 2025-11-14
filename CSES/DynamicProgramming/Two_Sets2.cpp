#include <bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
const int MOD=1e9+7;
void solve()
{
    int n, x, resul=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        resul+=i;
    }
    if(resul%2!=0)
    {
        cout<<0<<'\n';
        return;
    }
    resul/=2;
    vector<vector<int>>dp(n+1, vector<int>(resul+1, 0));
    dp[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=resul; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-i>=0)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-i])%MOD;
            }
        }
    }
    cout<<(dp[n][resul]*500000004)%MOD<<'\n';
 
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--)
    {
        solve();
    }
}