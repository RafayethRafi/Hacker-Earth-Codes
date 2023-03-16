#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int N = 2e5+10;
int multiples_cnt[N];
int hsh[N];

int main()
{
    optimize();
    int n,q;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        hsh[x]++;
    }
    

    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            multiples_cnt[i] += hsh[j];
        }
    }

    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        long long lcm = (a*1LL*b)/(__gcd(a,b));
        long long ans = multiples_cnt[a] + multiples_cnt[b];
        if(lcm<N) ans -= multiples_cnt[lcm];

        cout<<ans<<endl;
    }

    return 0;
}
