#include <iostream>
#include <vector>
using namespace std;

int LCS(string s1, string s2) 
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Build the DP table
    for (int i = 1; i <= m; ++i) 
    {
        for (int j = 1; j <= n; ++j) 
        {
            if (s1[i - 1] == s2[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n]; // Return the length of the LCS
}

int main() 
{
    string s1 = "ABCBDAB", s2 = "BDCABB";
    cout << "Length of LCS: " << LCS(s1, s2) << endl; // Output: 4
    return 0;
}
