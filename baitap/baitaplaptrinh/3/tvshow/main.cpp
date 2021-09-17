#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

struct pii
{
	int x, y;
}a[100001];

bool tang(pii t, pii z)
{
	return (t.x < z.x || (t.x == z.x && t.y > z.y));
}

void ReadData()
{
	cin >> n;
	for (int i = 1; i <= n * 2; i = i + 2) {
		cin >> a[i].x;
		a[i].y = 0;
		cin >> a[i + 1].x;
		a[i + 1].y = 1;
	}
	sort(a + 1, a + 1 + 2 * n, tang);
}

int inapproShows()
{
	int sahs = 0, cnt = 0;
	for (int i = 1; i <= n * 2; i = ++i) {
		if (a[i].y == 0) {
			cnt = cnt + sahs;
			sahs++;
		}
		else sahs--;
	}
	return cnt;
}

int main()
{
	freopen("tvshow.inp", "r", stdin);
	freopen("tvshow.out", "w", stdout);
	ReadData();
	cout << inapproShows();
}