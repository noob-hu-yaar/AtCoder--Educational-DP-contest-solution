

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    fast_io;

    ll n,k;
    cin>>n>>k;

    vector<ll> h(n+1);

    for(ll i=0;i<n;i++)
    cin>>h[i];
    vector<ll> dp(n+1);

    //base case
    dp[0] = 0;

    for(ll i=1;i<n;i++)
    {
        dp[i] = INT_MAX;
        for(ll j=i-1;j>=0 && (i-j)<=k;j--)
        {
            dp[i] = min(dp[i], abs(h[j] - h[i]) + dp[j]);
        }
    }
    cout<<dp[n-1]<<endl;
    
return 0;
}
