#include <iostream>
#include <vector>

using namespace std;

class BadNeighbors
{
public:
	vector<int> donation;
	int dp[40][2];
	int maxDonations(vector<int> donations)
	{
		donation = donations;
		memset(dp, -1, sizeof(dp));
		return get_donation(0, false);
	}
	int get_donation(int index, bool first_picked)
	{
		if (index >= donation.size())
			return 0;
		if (dp[index][first_picked] != -1)
			return dp[index][first_picked];
		if (index + 1 == donation.size())
		{
			if (first_picked)
				return dp[index][first_picked] = 0;
			return dp[index][first_picked] = donation[index];
		}
		if (index == 0)
		{
			return dp[index][first_picked] =
				max(donation[index]+get_donation(index+2, true), get_donation(index+1, false));
		}
		if (first_picked)
			return dp[index][first_picked] =
				max(donation[index]+get_donation(index+2, true), get_donation(index+1, true));
		return dp[index][first_picked] =
			max(donation[index]+get_donation(index+2, false), get_donation(index+1, false));
	}
};

int main(void)
{
	BadNeighbors bn;
	vector<int> donations;
	int done[] = {94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95,
	265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72};
	donations.assign(done, done+40);
	cout<<bn.maxDonations(donations)<<endl;
}
