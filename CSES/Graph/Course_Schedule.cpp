#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool> visi, novo;
stack<int>topo;
bool ciclo=false;
void dfs(int i)
{
	visi[i]=true;
    novo[i]=true;
	for(auto v : adj[i])
	{
		if(!visi[v])
		{
			dfs(v);
		}
        else
        {
            if(novo[v])
            {
                ciclo=true;
                return;
            }
        }
	}
    novo[i]=false;
	topo.push(i);
}
int main()
{
	int n, m, x, y, i;
	cin>>n>>m;
    visi.assign(n+1, false);
    novo.assign(n+1, false);
    adj.resize(n+1);
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(i=1; i<=n; i++)
    {
        if(!visi[i])
        {
            dfs(i);
            if(ciclo) break;
        }
    }
    if(ciclo)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        while(!topo.empty())
        {
            cout<<topo.top()<<" ";
            topo.pop();
        }
    }
}