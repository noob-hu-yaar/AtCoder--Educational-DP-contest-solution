

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    fast_io;
    
    int n;
    cin>>n;
    double p;
    double ans=0;
    
    vector<double> dp(n+1);
    dp[0] = 1;
    
    for(int coins=0;coins<n;coins++)
    {
        cin>>p;
        for(int i=coins+1;i>=0;i--)
        {
           // double s = (i==0) ? 0 : p*dp[i-1];
            dp[i] = (i==0 ? 0 : p*dp[i-1] )+ dp[i]*(1-p);
        }
    }
    
    for(int heads=0;heads<=n;heads++)
    {
        int tails = n-heads;
        if(heads > tails)
        ans += dp[heads];
    }
    cout<<sp(10)<<ans<<endl;
    
    return 0;
    
}
