#include<bits/stdc++.h>
using namespace std;
int countSubstrings(const string& str,const string& sub)
{
    if(sub.empty()) return 0;
    int count = 0;
    size_t pos = 0;

    while((pos = str.find(sub,pos)) != string::npos)
    {
        count++;
        pos += sub.length();
    }

    return count;
}
void solve()
{
    string a;
    int n;
    cin>>n;

    cin>>a;

    int count1 = countSubstrings(a,"map");
    int count2 = countSubstrings(a,"pie");
    int count3 = countSubstrings(a,"mapie");

    cout<<count1 + count2 - count3<<endl;


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
