#include <bits/stdc++.h>
#define int long long
#define V vector
#define ii pair<int,int>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
const int maxn=200005;
int p[maxn+1], r[maxn+1];
void inic(int n)
{
    for(int i=1; i<=n; i++)
    {
        p[i]=i;
        r[i]=1;
    }
}
int findf(int i)
{
    if(p[i]==i)
    {
        return i;
    }
    return p[i]=findf(p[i]);
}
void uniao(int a, int b)
{
    a=findf(a);
    b=findf(b);
    if(a!=b)
    {
        if(r[a]>r[b])
        {
            r[a]+=r[b];
            p[b]=a;
        }
        else
        {
            r[b]+=r[a];
            p[a]=b;
        }
    }
}
void solve()
{
    int n, m, comp, maior=0;
    cin>>n>>m;
    comp=n;
    inic(n);
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        if(findf(x)!=findf(y))
        {
            uniao(x, y);
            comp--;
            maior=max(maior, r[findf(x)]);
        }
        cout<<comp<<" "<<maior<<'\n';
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