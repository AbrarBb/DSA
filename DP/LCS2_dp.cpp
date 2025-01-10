#include <bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int dp[m+1][n+1] = {};
    
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j] = s1[i-1]==s2[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
        }
            
    }
    
    string ans;
    for(int i=m,j=n; i>0 && j>0;)
    {
        if(s1[i-1]==s2[j-1]) 
        {
            ans=s1[--i]+ans;
            j--;
        }
        else dp[i-1][j]>dp[i][j-1] ? i-- : j--;
    }
    return ans;
}

int main() {
    cout << lcs("STONE", "LONGEST");  // prints ONE
    return 0;
}
