#include <iostream>

using namespace std;

class ColorfuleBoxesAndBalls
{
public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int total = 0;
		if (bothColors * 2 > onlyRed + onlyBlue)
		{
			int cnt = min(numRed, numBlue);
			total = cnt * bothColors * 2;
			numRed -= cnt;
			numBlue -= cnt;
			if (numRed == 0)
				total += onlyBlue * numBlue;
			else
				total += onlyRed * numRed;
		} else
		{
			total += numRed * onlyRed;
			total += numBlue * onlyBlue;
		}
		return total;
	}
};

int main(void)
{
	ColorfuleBoxesAndBalls cbab;
	cout<<cbab.getMaximum(2, 3, 100, 400, 200)<<endl;
}
