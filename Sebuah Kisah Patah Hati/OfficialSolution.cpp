#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int prefSum[25];
int prefFrek[25];
int frek[25];
int tab[25];

bool cek(vector<int> demands)
{
	memset(frek,0,sizeof(frek));
	memset(prefSum,0,sizeof(prefSum));
	memset(frek,0,sizeof(frek));
	sort(demands.begin(),demands.end());
	reverse(demands.begin(),demands.end());
	int n = demands.size();
	int RemSum = 0;
	for (int i = 0 ; i < demands.size() ; i++)
	{
		frek[demands[i]]++;
		RemSum += demands[i];
	}
	prefFrek[0] = frek[0];
	for (int i = 1 ; i <= 20 ; i++)
	{
		prefSum[i] = prefSum[i - 1] + i * frek[i];
		prefFrek[i] = prefFrek[i - 1] + frek[i];
	}
	int curSum = 0;
	for (int i = 0 ; i < demands.size() ; i++)
	{
		int ix = i + 1;
		int sisa = n - ix;
		curSum += demands[i];
		RemSum -= demands[i];
		int kanan = ix * (ix - 1);
		if (ix > demands[i])
			kanan += RemSum;
		else
		{
			kanan += prefSum[ix - 1];
			kanan += (sisa - prefFrek[ix - 1]) * ix;
		}
		if (kanan < curSum) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;	
	for (int i = 0 ; i < n ; i++)
		cin >> tab[i];
	int ans = 0;
	for (int i = 1 ; i < (1 << n) ; i++)
	{
		vector<int> demands;
		int sum = 0;
		for (int j = 0 ; j < n ; j++) if (i & (1 << j))
		{
			demands.push_back(tab[j]);
			sum += tab[j];
		}
		if (sum % 2 == 1) continue;
		if (cek(demands))
		{
			ans = max(ans,(int)__builtin_popcount(i));
		}
	}
	cout << ans << endl;
}