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
const int INF = 1e9;
const int MOD = 1e9+7;
const int maxn=200005;
V<V<int>>adj, adj2;
V<bool>visi;
void dfs(int i, stack<int>&s){
    visi[i]=true;
    for(auto v : adj[i]){
        if(!visi[v]){
            dfs(v, s);
        }
    }
    s.push(i);
}
void dfs2(int i, V<int>&comp)
{
    visi[i]=true;
    comp.push_back(i);
    for(auto v : adj2[i]){
        if(!visi[v]){
            dfs2(v, comp);
        }
    }
}
void solve()
{
    int n, m, cont=0, p=0;
    cin>>n>>m;
    stack<int>s;
    visi.assign(n+1, false);
    adj.assign(n+1, V<int>());
    adj2.assign(n+1, V<int>());
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj2[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        if(!visi[i])
        {
            dfs(i, s);
        }
    }
    visi.assign(n+1, false);
    V<V<int>>compo;
    while(!s.empty()){
        if(!visi[s.top()]){
            cont++;
            V<int>comp;
            dfs2(s.top(), comp);
            compo.push_back(comp);
        }
        s.pop();
    }
    if(cont==1)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
        cout<<compo[1][0]<<" "<<compo[0][0]<<'\n';
    }
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