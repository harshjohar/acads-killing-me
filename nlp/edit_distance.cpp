#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define pii pair<int, int>
#define vi vector<int>
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define int long long
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int editDistance(string a, string b)
{
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = i;
    for (int i = 0; i < m; i++)
        dp[0][i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] != b[j - 1])
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            else
                dp[i][j] = dp[i - 1][j - 1];
        }
    }
    return dp[n][m];
}

int32_t main()
{
    string a = "hello", b = "hellhole";
    cout << editDistance(a, b) << endl;
    return 0;
}