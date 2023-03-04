#include "Algorithms.h"

#include <vector>
#include <algorithm>
#include <numeric>

int Algorithms::levenshteinDistance(const std::string_view& s, const std::string_view& t)
{
	const auto m = static_cast<int>(s.length());
	const auto n = static_cast<int>(t.length());

	// Initialize vector with size n + 1 and values 0 to n
	std::vector<int> dp(n + 1);
	std::iota(dp.begin(), dp.end(), 0);

	for (int i = 1; i <= m; ++i)
	{
		int prev = dp[0];
		dp[0]    = i;

		for (int j = 1; j <= n; ++j)
		{
			int cur = dp[j];
			if (s[i - 1] == t[j - 1])
			{
				dp[j] = prev;
			}
			else
			{
				dp[j] = 1 + std::min({ prev, dp[j], dp[j - 1] });
			}
			prev = cur;
		}
	}

	return dp[n];
}
