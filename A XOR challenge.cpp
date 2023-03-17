#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int main()
{
    optimize();
    int c;
    cin>>c;
    int bit_ct = (int)log2(c) + 1;
    vector<int> set_bits;
    int a=0,b=0;
    for(int i=0;i<bit_ct;i++)
    {
        if(c & 1<<i)
        set_bits.push_back(i);
        else
        {
            a |= (1<<i);
            b |= (1<<i);
        }
    }

    long long ans = -1;

    int sz = 1<< set_bits.size();

    for(int mask =0;mask<sz;mask++)
    {
        int x = a, y = b;
        for(int j=0;j<set_bits.size();j++)
        {
            if(mask & (1<<j))
            {
                x |= (1<<set_bits[j]);
            }
            else y |= (1<< set_bits[j]);
        }
        ans = max(ans , x*1LL*y);
    }

    cout<<ans<<endl;
    return 0;
}
