
#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const ll v = 3001;
ll dp[v][v];

ll length(string& s,string& t,ll i,ll j)
{
   // memset(dp,-1,sizeof(dp));
    //Base case
    if(i>=s.size() || j>=t.size())
    return 0;

    //Lookup
    if(dp[i][j] != -1)
    return dp[i][j];

    //Rec case
    if(s[i] == t[j])
    return dp[i][j] = 1 + length(s,t,i+1,j+1);

    else
    return dp[i][j] = max(length(s,t,i+1,j), length(s,t,i,j+1));
}

int main()
{
   fast_io;
    string s,t;
    cin>>s>>t;
     memset(dp,-1,sizeof(dp));

    //cout<<length(s,t,0,0)<<endl;
  ll len = length(s,t,0,0);
  ll i=0,j=0;

   string ans = " ";
   while(len)
   {
       if(s[i] == t[j])
       {
           ans.pb(s[i]);
           i++;
           j++;
           len--;
       }
       else
       {
           if(dp[i][j+1] > dp[i+1][j])
           j++;
           else
           i++;
       }
   }
   cout<<ans<<endl;
   return 0;
}
