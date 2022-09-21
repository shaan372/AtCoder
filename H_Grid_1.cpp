#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    bool grid[n][m];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
                grid[i][j] = false;
            else
                grid[i][j] = true;
        }
    }
    vector<vector<long long int>> dp(n,vector<long long int>(m,0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!grid[i][j])
                dp[i][j] = 0;
            else
            {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
                dp[i][j] = dp[i][j] % M;
            }
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}
