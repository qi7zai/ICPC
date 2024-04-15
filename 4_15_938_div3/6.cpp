
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int p1, p2, p3, p4;
    cin >> p1 >> p2 >> p3 >> p4;
    int n = p4 / 2 + 1;
    int m;
    int flag1 = p1 & 1;
    int flag2 = p2 & 1;
    int flag3 = p3 & 1;
    if(flag1 == flag2 && flag2 == flag3) {
        m = p1 / 2 + p2 / 2 + p3 / 2 + 1;
        if(flag1 == 0) m--;
    }
    else if(flag1 == flag2) {
        if(p3) p3--;
        else {
            p1--;p2--;
            flag1 = p1 & 1;
        }
        if(flag1 == 0) {
                m = p1 / 2 + p2 / 2 + p3 / 2;
            }
            else m = p1 / 2 + p2 / 2 + p3 / 2 + 1;
    }
    else if(flag1 == flag3) {
        if(p2) p2--;
        else {
            p1--;p3--;
            flag1 = p1 & 1;
            
        }
        if(flag1 == 0) {
                m = p1 / 2 + p2 / 2 + p3 / 2;
            }
            else m = p1 / 2 + p2 / 2 + p3 / 2 + 1;
    }
    else {
        if(p1) p1--;
        else {
            p2--;p3--;
            flag2 = p2 & 1;
        }
        if(flag2 == 0) {
                m = p1 / 2 + p2 / 2 + p3 / 2;
            }
            else m = p1 / 2 + p2 / 2 + p3 / 2 + 1;
    }
    
    cout << n + m - 1 << endl;
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