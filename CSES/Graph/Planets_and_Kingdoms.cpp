#include <bits/stdc++.h>
#define int long long
#define V vector
#define ii pair<int,int>
using namespace std;
//Little Caio. By: Campos;
//A não olha o Varandas. By: Maryto;
/*
 * LE O PROBLEMA ATE O FINAL
 * LE OS SAMPLES, ENTENDE OS SAMPLES
 * LE INPUT, LE OUTPUT
 * LE OS CONSTRAINTS
 * By : Matheus_H_Campos
 */
const int INF = 1e18;
const int MOD = 1e9+7;
const int maxn=200005+5;
int n, m;
V<V<int>>adj, adj2;
V<bool>visi;
V<int>resul;
stack<int>s;
void dfs(int i)
{
    visi[i]=true;
    for(int u : adj[i])
    {
        if(!visi[u]) dfs(u);
    }
    s.push(i);
    
}
void dfs2(int i, int cont)
{
    visi[i]=true;
    resul[i]=cont;
    for(int u : adj2[i])
    {
        if(!visi[u])
        {
            dfs2(u, cont);
        }
    }
} 
void solve()
{
    int c=0;
    cin>>n>>m;
    adj.assign(n+1, V<int>());
    adj2.assign(n+1, V<int>());
    visi.assign(n+1, false);
    resul.assign(n+1, 0);
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj2[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        if(!visi[i]) dfs(i);
    }
    visi.assign(n, false);
    while(!s.empty())
    {
        int u=s.top();
        s.pop();
        if(!visi[u]) 
        {
            dfs2(u, c);
            c++;
        }
    }
    cout<<c<<'\n';
    for(int i=1; i<=n; i++)
    {
        cout<<resul[i]+1<<" ";
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