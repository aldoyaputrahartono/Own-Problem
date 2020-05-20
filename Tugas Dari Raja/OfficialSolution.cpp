#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	assert(s.length() == n);
	int sum = 0;
	for (int i = 0 ; i < n ; i++)
		sum += (s[i] - '0');
	sum %= 9;
	int tambah = 9 - sum;
	int kurang = sum;
	if (kurang == 0)
		kurang = 9;
	string ans = s;
	sort(ans.begin(),ans.end());
	s = ans;
	bool ada = 0;
	for (int i = n - 1 ; i >= 0 ; i--)
	{
		if ((ans[i] - '0') + tambah < 10)
		{
			ans[i] += tambah;
			ada = 1;
			break;
		}
	}
	if (!ada)
	{
		for (int i = 0 ; i < n ; i++)
		{
			if (ans[i] - '0' >= kurang)
			{
				ans[i] -= kurang;
				ada = 1;
				break;
			}
		}
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	assert(ans != s);
	if (!ada)
		cout << -1 << endl;
	else
		cout << ans << endl;
}