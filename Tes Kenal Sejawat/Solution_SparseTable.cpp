#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int spaQuery[20][200010];
int par[100010];
int LOG = 17;
int root;
vector<int> child[200010];
vector<int> vis;
vector<int> depth;
int occ[200010];
int tab[200010];
int q,n,t;
int Spa[200010][20];

void reset()
{
	for (int i=0;i<=n;i++)
		 child[i].clear();
	vis.clear();
	depth.clear();
	memset(occ,0,sizeof(occ));
	memset(Spa,-1,sizeof(Spa));
	memset(spaQuery,-1,sizeof(spaQuery));
	return;
}

void dfs(int u,int cur)
{
	vis.push_back(u);
	depth.push_back(cur);
	occ[u]=vis.size()-1;
	for (int i=0;i<child[u].size();i++)
	{
		dfs(child[u][i],cur+1);
		vis.push_back(u);
		depth.push_back(cur);
	}
	return;
}

void build()
{
	for (int i=0;i<2*n-1;i++)
	{
		Spa[i][0]=i;
	}
	for (int j=1;(1<<j)<=2*n-1;j++)
		 for (int i=0;i+(1<<j)-1<2*n-1;i++)
		 {
		 	if (depth[Spa[i][j-1]]<depth[Spa[i+(1<<(j-1))][j-1]])
		 		 Spa[i][j]=Spa[i][j-1];
		 	else
		 		 Spa[i][j]=Spa[i+(1<<(j-1))][j-1];
		 }
	return;
}

int LCA(int l,int r)
{
	l = occ[l];
	r = occ[r];
	if (l>r)
		 swap(l,r);
	int k = 0;
	while ((1 << k) <= (r - l + 1)) ++k;
	--k;
	if (depth[Spa[l][k]]<=depth[Spa[r-(1<<k)+1][k]])
		 return vis[Spa[l][k]];
	else
		 return vis[Spa[r-(1<<k)+1][k]];
}

void buildSpa()
{
	for (int i = 1 ; i <= n ; i++)
		spaQuery[0][i] = tab[i];
	// cout <
	// cout << spaQuery[0][3] << endl;
	for (int i = 1 ; (1 << i) <= n ; i++)
		for (int j = 1 ; j + (1 << i) - 1 <= n ; j++)
		{
			// assert (spaQuery[i - 1][j] != -1 && spaQuery[i - 1][j + (1 << (j - 1))] != -1);
			// cout << i << " " << j << " -> " << spaQuery[i - 1][j] << " " << spaQuery[i - 1][j + (1 << (i - 1))] << endl;
			// cout << j + (1 << (i - 1)) << endl;
			spaQuery[i][j] = LCA(spaQuery[i - 1][j],spaQuery[i - 1][j + (1 << (i - 1))]);
		}
	return;
}

int query(int l,int r)
{
	if (l > r)
		swap(l,r);
	// int k = (int)(log2(r - l + 1));
	int k = 0;
	while ((1 << k) <= (r - l + 1)) ++k;
	--k;
	int ret = LCA(spaQuery[k][l],spaQuery[k][r - (1 << k) + 1]);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> q;
		reset();
		root = -1;
		for (int i = 0 ; i < n ; i++)
		{
			cin >> par[i];
			--par[i];
			if (par[i] == -2)
				root = i;
			if (i != root)
			{
				child[par[i]].push_back(i);
			}
		}
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
			--tab[i];
		} 
		dfs(root,0);
		build();
		buildSpa();
		while (q--)
		{
			int l,r;
			cin >> l >> r;
			int ans = query(l,r);
			cout << ans + 1 << endl;
		}
	}
}