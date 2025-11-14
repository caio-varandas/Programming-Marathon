#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
const int MOD=1e9+7;
vector<vector<int>>adj, dp;
int dfs(int mask, int i)
{
    //ao fazer 1<<u estamos pegando a mascara da posição da cidade
    if(i==n-1)
    {
        //essa mascara ja foi concluida 
        if(mask==(1<<n)-1)
        {
            return 1;
        }
        return 0;
    }
    if(dp[mask][i]!=-1)
    {
        return dp[mask][i];
    }
    int cont=0;
    for(auto u:adj[i])
    {
        //ja visitei?
        if(!(mask & (1<<u)))
        {
            int nova=mask | (1<<u);
            cont+=dfs(nova, u)%MOD;
        }
    }
    return dp[mask][i]=cont%MOD;
}
void solve(){
    cin>>n>>m;
    int x, y;
    adj.resize(n);
    dp.assign((1<<n), vector<int>(n, -1));
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        x--, y--;
        adj[x].push_back(y);
    }
    cout<<dfs(1, 0)<<'\n';
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