#include <iostream>
#include <cstdio>

using namespace std;

int h, w;
string rows[100];

void ReadData()
{
	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		cin >> rows[i];
	}
}

int Area()
{
	int ans = 0;
	bool inArea = false;
	for (int i = 0; i < h; i++)
	{
		inArea = false;
		for (int j = 0; j < w; j++)
		{
			if (rows[i][j] == '/' || rows[i][j] == '\\') {
				ans += 1;
				inArea = !inArea;
			}
			else if (inArea) ans += 2;

		}
	}
	return ans;
}

int main()
{
	freopen("ascii.inp", "r", stdin);
	freopen("ascii.out", "w", stdout);

	ReadData();
	cout << Area() / 2.0;

	return 0;
}
