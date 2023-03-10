#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,i;
        cin>>n>>k;

        multiset<long long> bags;

        for(i=0;i<n;i++)
        {
            long long x;
            cin>>x;

            bags.insert(x);
        }

        long long ans=0;
        while(k--)
        {
            auto last_it = --bags.end();
            long long x = *last_it;
            ans += x;
            bags.erase(last_it);
            bags.insert(x/2);
        }

        cout<<ans<<endl;
    }
    return 0;
}
