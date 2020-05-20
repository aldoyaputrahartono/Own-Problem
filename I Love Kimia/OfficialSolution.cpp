#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector< ll > tab;
	tab.push_back(2);
	while (tab.back() <= (ll)1e18)
	{
		ll ix = (ll)tab.size() + 1;
		ll tmp = 2 * ix * ix;
		tab.push_back(tmp + tab.back());
	}
	ll t;
	cin >> t;
	while (t--)
	{
		ll k;
		cin >> k;
		ll ix = lower_bound(tab.begin(),tab.end(),k) - tab.begin() + 1;
		cout << ix << endl;
	}
	return 0;
}