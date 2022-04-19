
 //BISMILLAHIR RAHMANIR RAHIM

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  endl '\n'
int main()
{
    optimize();

    int m,n,i;
    cin>>m>>n;

    priority_queue<int>q;

    for(i=0;i<m;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }

    long long ans = 0;


    for(i=0;i<n;i++)
    {
        if(!q.empty())
        {
            int a = q.top();
            q.pop();

            ans += a;
            a--;
            if(a>0)q.push(a);
    }
    }

    cout<<ans<<endl;

    return 0;
}
