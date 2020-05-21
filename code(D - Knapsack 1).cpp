

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

//ll dp[101];
ll dp[101][100005];
/*struct ks
{
    ll weight,value;
};*/

ll fun(ll w, ll n, ll weight[], ll value[])
{
    
    //Base case
    if(n==0)
    return 0;
    if(w <= 0)
    return 0;

    //Lookup
    if(dp[n][w] != -1)
    return dp[n][w];

    //Rec case
    ll op1 = (w-weight[n] >= 0) ? (value[n] + fun(w-weight[n], n-1,weight, value)) : INT_MIN;
    ll op2 = fun(w, n-1,weight,value);

    return dp[n][w] = max(op1, op2); 
}

int main()
{
    fast_io;

    ll n,w;
    cin>>n>>w;
    //vector<ks> ar;
    ll weight[n+1],value[n+1];

    for(ll i=1;i<=n;i++)
    cin>>weight[i]>>value[i];

    memset(dp,-1,sizeof(dp));
    cout<<fun(w,n,weight,value)<<endl;

    return 0;
}
