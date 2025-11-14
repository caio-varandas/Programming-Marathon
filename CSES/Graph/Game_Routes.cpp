#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
const int MOD=1e9+7;
void solve(){
    cin>>n>>m;
    int x, y;
    vector<vector<int>>adj(n);
    vector<int>grau(n, 0), ordem;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        x--, y--;
        adj[x].push_back(y);
        grau[y]++;
    }
    stack<int>s;
    for(int i=0; i<n; i++)
    {
        if(grau[i]==0)
        {
            s.push(i);
        }
    }
    while(!s.empty())
    {
        int u=s.top();
        s.pop();
        ordem.push_back(u);
        for(int v : adj[u])
        {
            grau[v]--;
            if(grau[v]==0)
            {
                s.push(v);
            }
        }
    }
    vector<int>dp(n, 0);
    dp[0]=1;
    for(int u : ordem)
    {
        for(int v : adj[u])
        {
            dp[v]=(dp[v]+dp[u])%MOD;
        }
    }
    cout<<dp[n-1]<<'\n';
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