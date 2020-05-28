
#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll mod = 1e9 + 7;
ll dp[102][100005];

int fun(vector<ll>& a, ll n, ll k)
{
    //Base case
    for(ll j=0;j<=k;j++)
    dp[1][j] = (j > a[1]) ? 0 : 1;

    //BU
    for(ll i=2;i<=n;i++)
    {
        for(ll j=0;j<=k;j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j];
                dp[i][j] = (mod + dp[i][j])%mod;
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - ( (j-1-a[i] >= 0) ? dp[i-1][j-1-a[i]] : 0);
                dp[i][j] = (mod + dp[i][j])%mod;
            }
        }
    }
    return dp[n][k];
}

int main()
{
    fast_io;

    ll n,k;
    cin>>n>>k;

    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++)
    cin>>a[i];

    cout<<fun(a,n,k)<<endl;

    return 0;
}
