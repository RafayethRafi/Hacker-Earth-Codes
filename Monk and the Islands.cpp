#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1e4+123;
vector<int>adj[mx];
int lvl[mx];

void bfs(int s)
{
    memset(lvl,-1,sizeof(lvl));
    lvl[s] = 0;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int f = q.front();
        q.pop();

        for(auto u: adj[f])
        {
            if(lvl[u]==-1)
            {
                lvl[u] = lvl[f]+1;
                q.push(u);
            }
        }
    }
}
int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,m,i;
        for(i=0;i<=mx;i++) adj[i].clear();
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(1);
        cout<<lvl[n]<<endl;

    }
    return 0;
}
