

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    ll n,w;
    cin>>n>>w;

    vector<ll> weight(n),value(n);
    for(ll i=0;i<n;i++)
    cin>>weight[i]>>value[i];

    ll max_val = 0;
    for(ll&x : value)
    max_val += x;

    vector<ll> dp(max_val+1,INT_MAX);
    dp[0] = 0;

    for(ll i=0;i<n;i++)
    {
        for(ll j=max_val-value[i];j>=0;j--)
        {
            dp[j+value[i]] = min(dp[j+value[i]], dp[j]+weight[i]);
        }
    }
    ll ans = INT_MIN;
    for(ll i=0;i<=max_val;i++)
    {
        if(dp[i] <= w)
        ans = max(ans, i);
    }

    cout<<ans<<endl;
    return 0;
}
