#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

vector<int> adj[100010];
int rata[100010];
int in[100010];
int out[100010];
char tab[100010];
deque< int > tree[400010];
int lazy[400010];
int cnt = 1;
int n,q;

void dfs(int u,int prv)
{
	// cout << u << endl;
	rata[cnt] = u;
	in[u] = cnt++;
	for (int i = 0 ; i < adj[u].size() ; i++) if (adj[u][i] != prv)
	{
		dfs(adj[u][i],u);
	}
	out[u] = cnt - 1;
}

void build(int node,int l,int r)
{
	tree[node].resize(26,0);
	if (l == r)
	{
		tree[node][tab[rata[l]] - 'a']++;
		return;
	}
	int mid = (l + r) >> 1;
	int child = node << 1;
	build(child,l,mid);
	build(child | 1,mid + 1,r);
	for (int i = 0 ; i < 26 ; i++)
		tree[node][i] = tree[child][i] + tree[child | 1][i];
}

void upd(int node,int val)
{
	val %= 26;
	lazy[node] += val;
	lazy[node] %= 26;
	for (int i = 1 ; i <= val ; i++)
	{
		int tmp = tree[node].back();
		tree[node].pop_back();
		tree[node].push_front(tmp);
	}
}

void propagate(int node)
{
	upd(node * 2,lazy[node]);
	upd(node * 2 + 1,lazy[node]);
	lazy[node] = 0;
}

void rangeUpdate(int node,int nodeL,int nodeR,int queryL,int queryR)
{
	if (queryL > nodeR || queryR < nodeL) return;
	if (queryL <= nodeL && nodeR <= queryR)
	{
		upd(node,1);
		return;
	}
	propagate(node);
	int mid = (nodeL + nodeR) >> 1;
	int child = node << 1;
	rangeUpdate(child,nodeL,mid,queryL,queryR);
	rangeUpdate(child | 1,mid + 1,nodeR,queryL,queryR);
	for (int i = 0 ; i < 26 ; i++)
		tree[node][i] = tree[child][i] + tree[child | 1][i];
}

deque< int > query(int node,int nodeL,int nodeR,int queryL,int queryR)
{
	deque< int > ret;
	ret.resize(26,0);
	if (queryL > nodeR || queryR < nodeL) return ret;
	if (queryL <= nodeL && nodeR <= queryR)
	{
		return tree[node];	
	}
	propagate(node);
	int mid = (nodeL + nodeR) >> 1;
	int child = node << 1;
	deque< int > kiri = query(child,nodeL,mid,queryL,queryR);
	deque< int > kanan = query(child | 1,mid + 1,nodeR,queryL,queryR);
	for (int i = 0 ; i < 26 ; i++)
		ret[i] = kiri[i] + kanan[i];
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 2 ; i <= n ; i++)
	{
		int parent;
		cin >> parent;
		adj[i].push_back(parent);
		adj[parent].push_back(i);
	}
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	dfs(1,0);
	build(1,1,n);
	int tot = 0;
	while (q--)
	{
		int ask,u;
		cin >> ask >> u;
		if (ask == 1)
		{
			rangeUpdate(1,1,n,in[u],out[u]);
		}
		else
		{
			string s;
			cin >> s;
			tot += s.length();
			deque< int > subtree = query(1,1,n,in[u],out[u]);
			deque< int > frek;
			frek.resize(26,0);
			for (int i = 0 ; i < s.length() ; i++)
				frek[s[i] - 'a']++;
			bool can = 1;
			for (int i = 0 ; i < 26 ; i++)
			{
				if (frek[i] > subtree[i])
				{
					can = 0;
					break;
				}
			}
			if (can)
				cout << "YA\n";
			else
				cout << "TIDAK\n";
		}
	}
}