#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StockHistory
{
public:
	int get_num_stocks(string stockPrices)
	{
		int result = 0;
		for (int i=0; i<stockPrices.size(); i++) {
			if (stockPrices[i] == ' ')
				result++;
		}
		result++;
		return result;
	}
	int maximumEarnings(int initialInvestment, int monthlyContribution, vector<string> stockPrices)
	{
		int money = initialInvestment;
		int month = stockPrices.size();
		int numStock = get_num_stocks(stockPrices[0]);
		double max = 0, profit = 0;
		bool buy[50] = {false};
		double proportion[50] = {0};
		int prices[50][999];
		for (int i=0; i<month; i++) {
			int price_length = 0;
			int j=0;
			for (int k=0; k<stockPrices[i].size(); k++) {
				if (stockPrices[i][k] != ' ')
					price_length++;
				else
				{
					string num = stockPrices[i].substr(k-price_length, price_length);
					price_length = 0;
					prices[i][j++] = stoi(num);
				}
			}
			string num = stockPrices[i].substr(stockPrices[i].size()-price_length, price_length);
			prices[i][j++] = stoi(num);
		}
		for (int i=month - 2; 0<= i; i--) {
			for (int j=0; j<numStock; j++) {
				double p = 1.0 * prices[month-1][j] / prices[i][j] - 1;
				if (0 < p && max < p) {
					buy[i] = true;
					max = p;
					proportion[i] = p;
				}
			}
		}
		for (int i=0; i<month; i++) {
			if (buy[i]) {
				profit += money * proportion[i];
				money = 0;
			}
			money += monthlyContribution;
		}
		return (int)round(profit);
	}

};

int main(void)
{
	StockHistory sh;
	vector<string> sp;
	sp.push_back("40 50 60");
	sp.push_back("37 48 55");
	sp.push_back("100 48 50");
	sp.push_back("105 48 47");
	sp.push_back("110 50 52");
	sp.push_back("110 50 52");
	sp.push_back("110 51 54");
	sp.push_back("109 49 53");
	cout<<sh.maximumEarnings(100, 20, sp)<<endl;
}
