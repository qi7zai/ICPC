
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    string x,y;
    cin>>x>>y;
    vector<int>a,b;
    for(auto i:x)
    {
        a.push_back(i-'0');
    }
    for(auto i:y)
    {
        b.push_back(i-'0');
    }
    bool flag = false;

    for(int i = 0;i < a.size();i++)
    {
        if(!flag)
        {
            if(a[i] == b[i])continue;
            else
            {
                if(a[i] < b[i])swap(a[i],b[i]);
                flag = true;
            }
        }
        else
        {
            if(a[i] > b[i])swap(a[i],b[i]);
        }
    }
    for(auto i:a)cout<<i;
    cout<<endl;
    for(auto i:b)cout<<i;
    cout<<endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
    

    return 0;
}