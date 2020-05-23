/*
    author: kartik8800
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define inf 1e9 + 1
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define MAX 3000

int dp[MAX+1][MAX+1];
string getLCS(string& s, string& t, int len)
{
        string LCS;
        int i = 0, j = 0;
        while(len > 0)
        {
            if(s[i] == t[j])
            {
                LCS.push_back(s[i]);
                i++;
                j++;
                len--;
            }
            else
            {
                if(dp[i][j+1] > dp[i+1][j])
                    j++;
                else i++;
            }
        }
        return LCS;
}

int lenLCS(string& s, string& t, int i, int j)
{
        if(i >= s.length() || j >= t.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j])
            return dp[i][j] = 1 + lenLCS(s,t,i+1,j+1);
        else 
        {
            return dp[i][j] = max(lenLCS(s,t,i,j+1), lenLCS(s,t,i+1,j));
        }
}

string solve(string s, string t)
{
        memset(dp, -1, sizeof dp);
        int len = lenLCS(s,t,0,0);
        return getLCS(s,t,len);
}
 
int main() {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t);
}
