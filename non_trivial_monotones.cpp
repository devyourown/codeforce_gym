#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int N;
	cin>>N;
	string s;
	cin>>s;
	int result = 0;
	for (int i=1; i<N; i++)
	{
		if (i >= 2 && s[i-2] == s[i-1] && s[i-1] == s[i] && s[i] == 'a')
		{
			result++;
			continue;
		}
		if (s[i-1] == s[i] && s[i] == 'a')
			result += 2;
	}
	cout<<result<<endl;
}
