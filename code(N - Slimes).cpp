
#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define inf 1e18
using namespace std;

ll dp[401][401];
ll s[401];

ll sum(ll i, ll j)
{
    if(i == 0)
    return s[j];
    
    return (s[j] - s[i-1]);
}

ll fun(ll i, ll j)
{
    //Base Case
    if(i == j)
    return 0;
    if(i > j)
    return 0;
    
    //Lookup
    if(dp[i][j] != -1)
    return dp[i][j];
    
    //Rec Case
    ll ans = inf;
    for(ll k=i;k<j;k++)
    {
        ans = min(ans, fun(i,k)+fun(k+1,j)+sum(i,j));
    }
    
    return dp[i][j] = ans;
}

int main()
{
    fast_io;
    
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    cin>>s[i];
    
    for(ll i=1;i<n;i++)
    {
        s[i] += s[i-1];
    }
    memset(dp,-1,sizeof(dp));
    
    cout<<fun(0,n-1)<<endl;
    
    return 0;
}
