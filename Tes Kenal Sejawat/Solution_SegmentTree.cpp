#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tree[400010];
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

void build(int node,int l,int r)
{
	if (l == r)
	{
		tree[node] = tab[l];
		return;
	}
	int mid = (l + r) >> 1;
	int child = node << 1;
	build(child,l,mid);
	build(child | 1,mid + 1,r);
	tree[node] = LCA(tree[child],tree[child | 1]);
	return;
}

int query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
	if (queryL > nodeR || queryR < nodeL) return -1;
	if (queryL <= nodeL && nodeR <= queryR) return tree[node];
	int mid = (nodeL + nodeR) >> 1;
	int child = node << 1;
	int kiri = query(child,nodeL,mid,queryL,queryR);
	int kanan = query(child | 1,mid + 1,nodeR,queryL,queryR);
	if (kiri == -1) return kanan;
	if (kanan == -1) return kiri;
	return LCA(kiri,kanan);
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
		build(1,1,n);
		while (q--)
		{
			int l,r;
			cin >> l >> r;
			int ans = query(1,1,n,l,r);
			cout << ans + 1 << endl;
		}
	}
}