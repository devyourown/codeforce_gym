#include <iostream>

using namespace std;

class ColorfuleBoxesAndBalls
{
public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int total = 0;
		if (bothColors * 2> onlyRed + onlyBlue)
		{
			int cnt = min(numRed, numBlue);
			total = cnt * bothColors * 2;
			numRed -= cnt;
			numBlue -= cnt;
			if (numRed == 0)
			{
				if (onlyBlue > 0)
				{
					total += onlyBlue * numBlue;
				}
			} else
			{
				if (onlyRed > 0)
				{
					total += onlyRed * numRed;
				}
			}
		} else
		{
			if (onlyRed > 0)
			{
				total += numRed * onlyRed;
			}
			if (onlyBlue > 0)
			{
				total += numBlue * onlyBlue;
			}
		}
		return total;
	}
};

int main(void)
{
	ColorfuleBoxesAndBalls cbab;
	cout<<cbab.getMaximum(5, 5, 464, 464, 464)<<endl;
}
