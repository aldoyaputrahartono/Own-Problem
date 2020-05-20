#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

ll BIT[100010];
ll tab[100010];
ll n;

void upd(ll x,ll val)
{
	for ( ; x <= 100000 ; x += (x & -x))
		BIT[x] = max(BIT[x],val);
}

ll query(ll x)
{
	ll ret = 0;
	for ( ; x ; x -= (x & -x))
		ret = max(ret,BIT[x]);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
	}
	ll ans = -INF;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll cnt = query(tab[i]) + 1;
		ans = max(ans,cnt);
		upd(tab[i],cnt);
	}
	cout << ans << endl;
}