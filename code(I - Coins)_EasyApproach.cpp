

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

//vector<vector<double>> dp(3001,vector<double>(3001,-1));
double dp[3001][3001];
double fun(vector<double> &p, int i, int atleast_heads)
{
    //Base case
    if(atleast_heads == 0)
    return 1;

    if(i == 0)
    return 0;

    //Lookup
    if(dp[i][atleast_heads] > -0.9)
    return dp[i][atleast_heads];

    //Rec case
    //double op1 = p[i]*fun(p,i-1,atleast_heads-1);
    //double op2 = (1-p[i])*fun(p,i-1,atleast_heads);
    return dp[i][atleast_heads] = p[i]*fun(p,i-1,atleast_heads-1) + (1-p[i])*fun(p,i-1,atleast_heads);
}

int main()
{
    fast_io;

    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<double> p(n+1);

    for(int i=1;i<=n;i++)
    cin>>p[i];

    cout<<sp(10)<<fun(p,n,(n+1)/2)<<endl;

    return 0;
}