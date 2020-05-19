

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

struct act
{
    ll a,b,c;
};

int main()
{
    fast_io;

    ll n;
    cin>>n;
    vector<act> v(n+1);

    for(ll i=1;i<=n;i++)
    {
        cin>>v[i].a;
        cin>>v[i].b;
        cin>>v[i].c;
    }

    ll dp[n+1][3];
    //Base case
    dp[1][0] = v[1].a;
    dp[1][1] = v[1].b;
    dp[1][2] = v[1].c;

    //BU
    for(ll i=2;i<=n;i++)
    {
        dp[i][0] = v[i].a + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = v[i].b + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = v[i].c + max(dp[i-1][0], dp[i-1][1]);
    }

    cout<< max(dp[n][0], max(dp[n][1], dp[n][2])) <<endl;
    return 0;
}
