#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int main()
{
    optimize();
    map<int,multiset<string>> mp;
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int marks;
        string name;
        cin>>name>>marks;

        mp[-1*marks].insert(name);
    }

    for(auto &x : mp)
    {
        auto &students = x.second;
        int marks = x.first;

        for(auto &u : students)
        {
            cout<<u<<" "<<(-1*marks)<<endl;
        }
    }


    return 0;
}
