#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1000;
int lvl[mx];
vector<int>adj[mx];

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
    int n,i;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    int ans = INT_MAX, p = INT_MAX;
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(lvl[x]<p)
        {
            p = lvl[x];
            ans = min(ans,x);
        }
    }

    cout<<ans<<endl;

    return 0;
}
