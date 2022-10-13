#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class BatchSystem
{
public:
	bool user_cmp(const pair<string, int>& a,const pair<string, int>& b) {
		return a.first < b.first;
	}
	bool time_cmp(const pair<string, int>& a, const pair<string, int>& b) {
		return a.second < b.second;
	}
	vector<int> schedule(vector<int> duration, vector<string> user)
	{
		map<string, int> m;
		map<string, int> user_index;
		for (int i=0; i<duration.size(); i++) {
			user_index.insert({user[i], i});
			m.insert({user[i], duration[i]});
		}
		vector<pair<string, int>> work_time(m.begin(), m.end());
		sort(work_time.begin(), work_time.end(), user_cmp);
		sort(work_time.begin(), work_time.end(), time_cmp);
		vector<int> result;
		for (int i=0; i<duration.size(); i++) {
			result.push_back(user_index[work_time[i].first]);
		}
		return result;
	}
};

int main(void)
{
	BatchSystem bs;
	vector<int> duration;
	vector<string> user;
	duration.push_back(400);
	duration.push_back(100);
	duration.push_back(100);
	duration.push_back(100);
	user.push_back("Danny");
	user.push_back("Stella");
	user.push_back("Stella");
	user.push_back("Mac");
	vector<int> result = bs.schedule(duration, user);
	for (int i=0; i<result.size(); i++) {
		cout<<result[i]<<endl;
	}
}
