

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define s 3003
using namespace std;

ll dp[s][s];

ll solve(vector<ll>& a, ll i, ll j)
{
    //Base case
    if(i > j)
    return 0;
    
    //Lookup
    if(dp[i][j] != -1)
    return dp[i][j];
    
    //Rec Case
    ll op1 = a[i] + min( solve(a,i+1,j-1), solve(a,i+2,j));
    ll op2 = a[j] + min( solve(a,i+1,j-1), solve(a,i,j-2));
    
    return dp[i][j] = max(op1,op2);
}

int main()
{
    fast_io;
    
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    memset(dp,-1,sizeof(dp));
    ll X = solve(a,0,n-1);
    
    ll sum = 0;
    for(ll j=0;j<a.size();j++)
    sum += a[j];
    
    ll Y = sum - X;
    cout<<X-Y<<endl;
    
    return 0;
}
