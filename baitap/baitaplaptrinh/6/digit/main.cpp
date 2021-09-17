#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

/*
int digits[100000];

void Digits(string s)
{
	for(int i = 0; i < s.length(); ++i){
		digits[i] = s[i] - '0';
	}

	//for(int i = 0; i < s.length(); ++i){
	//    cout<<digits[i+1]<<endl;
	//}
}

string MaxNum(string s, int k)
{
	int M = 0, mPos;
	string finalStr = "";
	int i = 0;
	while(i < s.length()){
		if(k > 0){
			if(digits[i] > M){
				M = digits[i];
				mPos = i;
			}
			k--;
		}
		else{
			finalStr += (char)(M + '0');
			i = mPos - 1;
			M = 0;
		}
		i++;
	}
	return finalStr;
}
*/

string MaxNum(string s, int k)
{
	string t = "";
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		while (t != "" &&
			s[i] > t[t.length() - 1] &&
			k > 0) {
			t.pop_back();
			k--;
		}
		if (k > 0) t = t + s[i];
		if (k <= 0) {
			t = t + s.substr(i, s.length() - 1);
			break;
		}
		//cout << t << endl;
	}
	return t;
}

int main()
{
	freopen("digit.inp", "r", stdin);
	freopen("digit.out", "w", stdout);

	/*
	string s;
	int k;
	cin >> s;
	cin >> k;

	Digits(s);
	MaxNum(s, k);
	*/

	int k;
	string s;
	cin >> s;
	cin >> k;
	cout << MaxNum(s, k);

	return 0;
}