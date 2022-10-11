#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[50];

class CorporationSalary
{
public:
	long long totalSalary(vector<string> relations)
	{
		long long result = 0;
		for (int i=0; i<relations.size(); i++)
		{
			set_salary(relations, i);
		}
		for (int i=0; i<relations.size(); i++)
		{
			cout<<dp[i]<<endl;
			result += dp[i];
		}
		return result;
	}
	void	set_salary(vector<string> relations, int index)
	{
		if (relations[index].find("Y") == string::npos)
		{
			dp[index] = 1;
			return ;
		}
		int salary = 0;
		for (int i=0; i<relations.size(); i++)
		{
			if (relations[index][i] == 'Y')
			{
				if (dp[i] == 0)
				{
					set_salary(relations, i);
				}
				salary += dp[i];
			}
		}
		dp[index] = salary;
	}
};

int main(void)
{
	CorporationSalary cs;
	vector<string> relations;
	relations.push_back("NNNN");
	relations.push_back("NNNN");
	relations.push_back("NNNN");
	relations.push_back("NNNN");
	cout<<cs.totalSalary(relations)<<endl;
}
