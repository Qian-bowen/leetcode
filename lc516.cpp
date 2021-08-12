#include<iostream>
#include<vector>
using namespace std;

int longestPalindromeSubseq(string s) {
	int n = s.length();
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = n - 1;i >= 0;--i)
	{
		dp[i][i] = 1;
		for (int j = i+1;j < n;++j)
		{
			if (s[i] == s[j])
			{
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else
			{
				int tmp1 = dp[i + 1][j],tmp2=dp[i][j-1];
				dp[i][j] = (tmp1 >= tmp2) ? tmp1 : tmp2;
			}
		}
	}
	return dp[0][n - 1];
}

int main()
{
	string s = "aaabba";
	cout << longestPalindromeSubseq(s);
	return 0;
}