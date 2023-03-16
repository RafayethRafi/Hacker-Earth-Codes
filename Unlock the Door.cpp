#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);


const int M = 1e9+7;
const int N = 1e5+123;
int fact[N];
int binExpo(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if (b & 1)
        {
            ans = (ans*1LL * a) % M;
        }

        a = (a*1LL*a)%M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    optimize();
    int t;
    cin>>t;
    fact[0] = 1;

    for(int i=1;i<N;i++)
    {
        fact[i] = (fact[i-1]*1LL*i) % M;
    }

    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ans = fact[n];
        ans = (ans* 1LL * fact[k])%M;
        int den = (fact[k-n] *1LL * fact[n])%M;

        ans = (ans *1LL* binExpo(den,M-2))%M;

        cout<<ans<<endl;
    }
    return 0;
}
