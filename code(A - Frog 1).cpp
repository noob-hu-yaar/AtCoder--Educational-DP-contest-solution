

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
    
    ll n;
    cin>>n;
    vector<ll> h(n+1);

    for(ll i=0;i<n;i++)
    cin>>h[i];
    vector<ll> dp(n+1);

    //base case
    dp[0] = 0;
    dp[1] = h[1] - h[0];

    //BU
    for(ll i=2;i<n;i++)
    {
        ll op1 = dp[i-1] + abs(h[i]-h[i-1]);
        ll op2 = dp[i-2] + abs(h[i]-h[i-2]);
        dp[i] = min(op1,op2);
    }
    cout<< dp[n-1] <<endl;

    return 0;
}
