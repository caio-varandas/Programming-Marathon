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
V<V<ii>>adj;
V<int>dist, caminhos, minimo, maximo;
void dijkstra(int a)
{
    dist[a]=0;
    minimo[a]=0;
    caminhos[a]=1;
    maximo[a]=0;
    priority_queue<ii, V<ii>, greater<ii>>pq;
    pq.push({0, a});
    while(!pq.empty())
    {
        int u=pq.top().first;
        int t=pq.top().second;
        pq.pop();
 
        if(u>dist[t]) continue;
 
        for(auto [v, w] : adj[t])
        {
            if(dist[t]+w<dist[v])
            {
                dist[v]=dist[t]+w;
                caminhos[v]=caminhos[t];
                minimo[v]=minimo[t]+1;
                maximo[v]=maximo[t]+1;
                pq.push({dist[v], v});
            }
            else if(dist[t]+w==dist[v])
            {
                caminhos[v]=(caminhos[v]+caminhos[t])%MOD;
                minimo[v]=min(minimo[v], minimo[t]+1);
                maximo[v]=max(maximo[v], maximo[t]+1);
            }
        }
 
    }
}
void solve()
{
    cin>>n>>m;
    dist.assign(n, INF);
    caminhos.assign(n, 0);
    maximo.assign(n, 0);
    minimo.assign(n, INF);
    adj.assign(n, {});
    for(int i=0; i<m; i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        x--, y--;
        adj[x].push_back({y, z});
    }
    dijkstra(0);
    cout<<dist[n-1]<<" "<<caminhos[n-1]<<" "<<minimo[n-1]<<" "<<maximo[n-1]<<'\n';
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