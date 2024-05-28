#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t;
    std::cin >> s >> t;

    int n = std::size(s), m = std::size(t);
    std::vector dp(n + 1, std::vector(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            if (s[i - 1] == t[j - 1])
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }

    int x = n, y = m;
    std::string lcs;
    while (x > 0 and y > 0)
    {
        if (dp[x][y] == dp[x - 1][y - 1] + 1)
            lcs += s[x - 1], x--, y--;
        else if (dp[x][y] == dp[x][y - 1])
            y--;
        else
            x--;
    }

    std::reverse(std::begin(lcs), std::end(lcs));
    std::cout << dp[n][m] << "\n"
              << lcs;

    return 0;
}