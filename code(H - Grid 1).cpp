

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
    ll ro,co;
    cin>>ro>>co;
    ll mod = 1e9+7;

    vector< vector<ll>> dp(ro+1, vector<ll> (co+1,0));
    dp[0][0] = 1;

    for(ll i=0;i<ro;i++)
    {
        string s;
        cin>>s;
        for(ll j=0;j<co;j++)
        {
            if(s[j] == '.')
            {
                if(i>0)
                {
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= mod;
                }
                if(j>0)
                {
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
            }
            else
            dp[i][j] = 0;

        }
    }
    cout<<dp[ro-1][co-1]<<endl;

    return 0;
}
