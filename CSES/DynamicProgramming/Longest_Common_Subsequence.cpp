#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, m;
    cin>>n>>m;
    vector<int>g(n), s(m), vet;
    for(int i=0; i<n; i++)
    {
        cin>>g[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>s[i];
    }
    
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(g[i-1]==s[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i=n, j=m;
    while(i>0 and j>0)
    {  
        if(g[i-1]==s[j-1])
        {
            vet.push_back(g[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    cout<<dp[g.size()][s.size()]<<'\n';
    for(i=vet.size()-1; i>=0; i--)
    {
        cout<<vet[i]<<" ";
    }
    cout<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}