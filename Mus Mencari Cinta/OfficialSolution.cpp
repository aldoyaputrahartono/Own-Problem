#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 1e3;

struct data
{
    int w;
    int l;
    int h;
};

bool connect[510][510];
bool vis[510];
int matched[510];
int n;
data tab[510];

bool dfs(int u)
{
    for (int i = 1 ; i <= n ; i++)
    {
        if (!vis[i] && connect[u][i])
        {
            vis[i] = 1;
            if (matched[i] == -1 || dfs(matched[i]))
            {
                matched[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(connect,0,sizeof(connect));
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> tab[i].w >> tab[i].l >> tab[i].h;
        }
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = i + 1 ; j <= n ; j++)
            {
                if (tab[i].w < tab[j].w && tab[i].l < tab[j].l && tab[i].h < tab[j].h)
                    connect[i][j] = 1;
                if (tab[i].w > tab[j].w && tab[i].l > tab[j].l && tab[i].h > tab[j].h)
                    connect[j][i] = 1;
            }
        }
        memset(matched,-1,sizeof(matched)); 
        int ans = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            memset(vis,0,sizeof(vis));
            ans += dfs(i);
        }
        ans = n - ans;
        cout << ans << endl;
    }
}