#include <iostream>

using namespace std;

bool pairings[50] = {0,};
int N;

class HandsShaking
{
public:
	long countPerfect(int n)
	{
		long long dp[n/2+1];
		dp[0] = 1;

		for (int i=1; i<=n/2; i++) {
			dp[i] = 0;
			for (int j=0; j<i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}

		return dp[n / 2];
	}
};

int main(void)
{
	HandsShaking hs;
	cout<<hs.countPerfect(50)<<endl;
}
