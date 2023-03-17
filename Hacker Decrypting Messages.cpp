#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int N = 1e6+10;
int a[N];
int hp[N];
int canRemove[N];
int hsh[N];

vector<int> distincPF(int x)
{
    vector<int> ans;

    while(x>1)
    {
        int pf = hp[x];
        while(x%pf==0) x/=pf;

        ans.push_back(pf);
    }

    return ans;
}

int main()
{
    optimize();
    int n,q,i,j;
    cin>>n>>q;

    for(i=2;i<N;i++)
    {
        if(hp[i]==0)
        {
        for(j=i;j<N;j+=i)
        {
            hp[j] = i;
        }
        }
    }
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        hsh[x]=1;
    }

    for(int i=2;i<N;i++)
    {
        if(hsh[i])
        {
            for(long long j=i;j<N;j*=i)
            {
                canRemove[j] = 1;
            }
        }
    }

    while(q--)
    {
        int x;
        cin>>x;
        vector<int> pf = distincPF(x);

        bool f= false;

        for(i=0;i<pf.size();i++)
        {
            for(j=i;j<pf.size();j++)
            {
                int product = pf[i]*pf[j];
                if(i==j && x%product!=0) continue;

                int toRemove = x/product;
                if( canRemove[toRemove]==1 || toRemove==1)
                {
                    f= 1;
                    break;
                }
            }
            if(f) break;
        }

        cout<< (f ? "YES" : "NO")<<endl;
    }
    return 0;
}
