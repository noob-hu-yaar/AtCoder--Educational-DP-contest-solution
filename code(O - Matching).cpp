

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll mod = 1e9+7;
ll dp[22][(1<<22)];

ll fun( vector< vector<ll>> &comp, ll N, ll i, ll woman_bit)
{
    //Base case
    if(i == N+1)
    {
        if(woman_bit == 0)
        return 1;
        return 0;
    }
    
    //Lookup
    if(dp[i][woman_bit] != -1)
    return dp[i][woman_bit];
    
    //Rec case
    ll ans = 0;
    for(ll w=0;w<N;w++)
    {
        bool is_avail = ( ((1<<w) & woman_bit) != 0) ? 1 : 0;
        
        if(is_avail && comp[i][w+1])
        {
            ans += fun( comp,N,i+1, (woman_bit ^ (1<<w)));
            ans %= mod;
        }
    }
    return dp[i][woman_bit] = ans;
}

int main()
{
    fast_io;
    
    ll N;
    cin>>N;
    
    vector< vector<ll>> comp(N+1, vector<ll>(N+1));
   //int comp[22][22];
    for(ll i=1;i<=N;i++)
    {
        for(ll j=1;j<=N;j++)
        cin>>comp[i][j];
    }
    
    memset(dp,-1,sizeof(dp));
    cout<<fun(comp,N,1,(1<<N)-1)<<endl;
    
    return 0;
}