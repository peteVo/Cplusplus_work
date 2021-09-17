#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxN 200001

using namespace std;

int n;
struct Time
{
	int time;
	int isStart;
} times[maxN];

bool tang(Time a, Time b)
{
	return (a.time < b.time || (a.time == b.time && a.isStart < b.isStart));
}

void ReadData()
{
	int cnt = 1;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> times[cnt].time;
		times[cnt++].isStart = 1;

		cin >> times[cnt].time;
		times[cnt++].isStart = 0;
	}

	int m = n * 2;
	sort(times + 1, times + 1 + m, tang);
	//cnt = 1;
	//for(int i = 1; i <= n; ++i){
    //    cout << times[cnt++].time << " " << times[cnt++].time << endl;
	//}
}

int MaxComputer()
{
	int usingComputers = 0, maxUsingComputers = 0;

	for (int i = 1, m = n * 2; i < m; ++i)
	{
		if (times[i].isStart == 1) usingComputers++;
		else usingComputers--;
		maxUsingComputers = max(maxUsingComputers, usingComputers);
	}
	return maxUsingComputers;
}

int main()
{
	freopen("phanmay.inp", "r", stdin);
	freopen("phanmay.out", "w", stdout);

	ReadData();
	cout << MaxComputer();

	return 0;
}
