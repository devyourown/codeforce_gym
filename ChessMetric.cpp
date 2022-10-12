#include <iostream>
#include <vector>

using namespace std;

int dy[16] = {-1, -1, -1, 0, 0, 1, 1, 1, -1, -2, -2, -1, 1, 2, 2, 1};
int dx[16] = {-1, 0, 1, -1, 1, -1, 0, 1, -2, -1, 1, 2, 2, 1, -1, -2};
long long dp[100][100][55] = {0};

class ChessMetric
{
public:
	int n, numMove;
	vector<int> end_point;
	long long howMany(int size, vector<int> start, vector<int> end, int numMoves)
	{
		int x, y, i, j;
		dp[start[0]][start[1]][0] = 1;
		for (i=1; i<= numMoves; i++)
		{
			for (x=0; x<size; x++)
			{
				for (y=0; y<size; y++)
				{
					for (j=0; j<16; j++)
					{
						int nx = x + dx[j];
						int ny = y + dy[j];
						if (nx < 0 || nx >= size || ny < 0 || ny >= size)
							continue;
						dp[ny][nx][i] += dp[y][x][i-1];
					}
				}
			}
		}
		return dp[end[0]][end[1]][numMoves];
	}
	long long get_route(int y, int x, int moves)
	{
		if (y < 0 || y >= n || x < 0 || x >= n)
			return 0;
		if (moves == numMove && y == end_point[0] && x == end_point[1])
			return dp[y][x][moves] = 1;
		if (moves == numMove)
			return dp[y][x][moves] = 0;
		if (dp[y][x][moves] != 0)
			return dp[y][x][moves];
		for (int i=0; i<16; i++)
		{
			dp[y][x][moves] += get_route(y+dy[i], x+dx[i], moves+1);
		}
		return dp[y][x][moves];
	}
};

int main(void)
{
	ChessMetric cm;
	vector<int> start;
	vector<int> end;
	start.push_back(0); start.push_back(0);
	end.push_back(0); end.push_back(99);
	cout<<cm.howMany(100, start, end, 50)<<endl;
}
