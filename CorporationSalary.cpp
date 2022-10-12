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
			result += set_salary(relations, i);
		}
		return result;
	}
	long long	set_salary(vector<string> relations, int index)
	{
		if (relations[index].find("Y") == string::npos)
		{
			return dp[index] = 1;
		}
		long long salary = 0;
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
		return dp[index] = salary;
	}
};

int main(void)
{
	CorporationSalary cs;
	vector<string> relations;
	relations.push_back("NNNNNN");
	relations.push_back("YNYNNY");
	relations.push_back("YNNNNY");
	relations.push_back("NNNNNN");
	relations.push_back("YNYNNN");
	relations.push_back("YNNYNN");
	cout<<cs.totalSalary(relations)<<endl;
}
