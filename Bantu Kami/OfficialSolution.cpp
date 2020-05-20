#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MOD = 1e9 + 7;

int BIT[90010];
int MAXN;

void upd(int x)
{
	for ( ; x <= MAXN ; x += (x & -x))
	{
		BIT[x]++;
		BIT[x] %= 2;
	}
	return;
}

int query(int x)
{
	int ret = 0;
	for ( ; x ; x -= (x & -x))
	{
		ret += BIT[x];
		ret %= 2;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	MAXN = n * n;
	vector<int> nums;
	int paritas_kosong = -1;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= n ; j++)
		{
			int isi;
			cin >> isi;
			if (isi == -1)
				paritas_kosong = (n - i + 1) % 2;
			else
				nums.push_back(isi);
		}
	int inv = 0;
	for (int i = 0 ; i < nums.size() ; i++)
	{
		int cnt = query(MAXN) - query(nums[i]);
		cnt %= 2;
		inv += cnt;
		inv %= 2;
		upd(nums[i]);
	}
	if (n % 2 == 1)
	{
		if (inv % 2 == 0)
			cout << "IYA\n";
		else
			cout << "TIDAK\n";
	}
	else
	{
		if (paritas_kosong != inv)
			cout << "IYA\n";
		else
			cout << "TIDAK\n";
	}
}