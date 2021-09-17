#include <iostream>
#include <cstdio>
#define maxN 1000000

using namespace std;
typedef long long ll;

ll sum[maxN + 1] = { 0 };

void Sieve()
{
	for (int i = 1; i <= maxN; ++i) {
		for (int j = i * 2; j <= maxN; j += i) {
			sum[j] += (ll)i;
		}
	}
}

int numsPP(int l, int r)
{
	int cnt = 0;

	for (int i = l; i <= r; ++i) {
		if (sum[i] > i) cnt++;
		//cout << i <<": sum = " << sum[i] << endl;
	}
	return cnt;
}

int main()
{
	freopen("PP.inp", "r", stdin);
	freopen("PP.out", "w", stdout);

	Sieve();

	int l, r;
	cin >> l >> r;
	cout << numsPP(l, r);

	return 0;
}