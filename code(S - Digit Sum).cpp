

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(x) fixed<<setprecision(x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const ll mod = 1e9 + 7;
//const int scope = 100005;
char k[100005];

void add_store(int &a, int b)
{
    (a += b) %= mod;
    
}

int main()
{
    fast_io;
    
    int D;
    cin>>k>>D;
    int length = strlen(k);
    
    vector< vector<int>> dp (D, vector<int> (2));
    dp[0][0] = 1;
    
    for(int pos=0;pos<length;pos++)
    {
        vector< vector<int>> dp1(D, vector<int>(2));
        for(int sum=0;sum<D;sum++)
        {
            for( bool small : {false,true})
            {
                for(int dig=0;dig<=9;dig++)
                {
                    
                    if(dig > pos[k]-'0' && small == false)
                    break;
                    
                    add_store( dp1[(sum+dig)%D][small || dig < pos[k]-'0'], dp[sum][small]);
                }
            }
        }
        dp = dp1;
    }
    
    int ans = dp[0][true] + dp[0][false];
    int res = (ans%mod)-1;
    
    //res =0 ? cout<<res : cout<<0;
  res == -1 ? cout<<mod-1 : cout<<res;
    cout<<endl;
    return 0;
}
