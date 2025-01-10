#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2) 
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    for(int i = 1; i <= m; i++) 
    {
        for(int j = 1; j <= n; j++) 
        {
            if(s1[i-1] == s2[j-1]) 
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "STONE";
    string s2 = "LONGEST";
    cout << LCS(s1, s2);  // prints 3 (LCS is "ONE")
    return 0;
}
