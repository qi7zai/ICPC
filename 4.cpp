
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    set<int> ans;
    ans.insert(x);
    while(m--) {
        set<int> tmp;
        int r;
        char c;
        cin >> r >> c;
        if(c == '0')
            for(auto num : ans) tmp.insert((num + r) % n == 0 ? n : (num + r) % n);
        else if(c == '1')
           for(auto num : ans) 
           {
            tmp.insert((num + n - r) % n == 0 ? n : (num + n - r) % n);
           }
        else    
            for(auto num : ans) {
                tmp.insert((num + r) % n == 0 ? n : (num + r) % n);
                tmp.insert((num + n - r) % n == 0 ? n : (num + n - r) % n);
            }
        ans = tmp;
    }
    cout << ans.size() << endl;
    for(auto num : ans) cout << num << ' ';
    cout << endl;
}
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    solve();
  }
  
}
