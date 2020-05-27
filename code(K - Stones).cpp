
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
    
    int n,k;
    cin>>n>>k;
    
    vector<int> v(n);
    for(int& i : v)
    cin>>i;
    
    vector<bool> dp(k+1,0);
    for(int i=0;i<=k;i++)
    {
        for(int move : v)
        {
            if(i-move>=0 && dp[i-move]==0)
            dp[i] = 1;
        }
    }
    
    (dp[k]>0) ? cout<<"First" : cout<<"Second";
    
    return 0;
}
