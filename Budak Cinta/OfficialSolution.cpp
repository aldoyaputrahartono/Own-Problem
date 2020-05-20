#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
// const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;

vector< pair<ll,ll> > Graph_adj[100010];
ll parent[100010];
ll dfs_num[100010];
ll dfs_low[100010];
ll num = 1;
bool vis[100010];
map< pair<ll,ll>,bool > mp;
ll cntBridge;

void dfs(ll u,ll prv)
{
	for (ll i = 0 ; i < Graph_adj[u].size() ; i++) if (Graph_adj[u][i].first != prv)
		dfs(Graph_adj[u][i].first,u);
}

//cari bridge
void FindBridge(ll u)
{
	dfs_num[u]=dfs_low[u]=num++;
	vis[u]=1;
	for (ll i=0;i<Graph_adj[u].size();i++)
	{
		if (!vis[Graph_adj[u][i].first])
		{
			parent[Graph_adj[u][i].first]=u;
			FindBridge(Graph_adj[u][i].first);
			dfs_low[u]=min(dfs_low[u],dfs_low[Graph_adj[u][i].first]);
			if (dfs_low[Graph_adj[u][i].first] > dfs_num[u])
			{	
				mp[make_pair(u,Graph_adj[u][i].first)] = mp[make_pair(Graph_adj[u][i].first,u)] = 1;
				++cntBridge;
			}
			
		}
		else
		 if (parent[u]!=Graph_adj[u][i].first)
		  dfs_low[u]=min(dfs_low[u],dfs_num[Graph_adj[u][i].first]);
	}
	return;
}

void FindBridge()
{
	memset(vis,0,sizeof(vis));
	cntBridge = 0;
	FindBridge(1);
}

//bikin Bridge-tree
vector< pair<ll,ll> > Tree_adj[100010];
queue<ll> q[100010];
ll ConnectedComponent;
ll n,m;
ll prov[100010];

void MakeBridgeTree(ll u)
{
	ll currcmp = ConnectedComponent;
	q[currcmp].push(u);
	vis[u] = 1;
	while (!q[currcmp].empty())
	{
		ll v = q[currcmp].front();
		q[currcmp].pop();
		prov[v] = currcmp;
		for (ll i = 0 ; i < Graph_adj[v].size() ; i++)
		{
			if (vis[Graph_adj[v][i].first]) continue;
			if (mp[make_pair(v,Graph_adj[v][i].first)])
			{
				++ConnectedComponent;
				Tree_adj[currcmp].push_back({ConnectedComponent,Graph_adj[v][i].second});
				Tree_adj[ConnectedComponent].push_back({currcmp,Graph_adj[v][i].second});
				MakeBridgeTree(Graph_adj[v][i].first);
			}
			else
			{
				q[currcmp].push(Graph_adj[v][i].first);
				vis[Graph_adj[v][i].first] = 1;
			}
		}
	}
}

void BuildBridgeTree()
{
	ConnectedComponent = 1;
	memset(vis,0,sizeof(vis));
	MakeBridgeTree(1);
	assert(ConnectedComponent == cntBridge + 1);
}

//bangun sparse table
//spa[0] simpan parent
//spa[1] simpan weight
ll spa[2][25][100010]; //[parent/weight][2^k][node_apa]
ll depth[100010];
const ll LOG = 24;

void dfs(ll u,ll prv,ll deep)
{
	depth[u] = deep;
	for (ll i = 0 ; i < Tree_adj[u].size() ; i++) if (Tree_adj[u][i].first != prv)
	{
		ll v = Tree_adj[u][i].first;
		spa[0][0][v] = u;
		spa[1][0][v] = Tree_adj[u][i].second;
		dfs(v,u,deep + 1);
	}
}

void buildSparseTable()
{
	memset(spa,-1,sizeof(spa));
	dfs(1,-1,1);
	for (ll i = 1 ; i <= LOG; i++)
	{
		for (ll j = 1 ; j <= ConnectedComponent ; j++) if (spa[0][i - 1][j] != -1)
		{
			spa[0][i][j] = spa[0][i - 1][spa[0][i - 1][j]];
			spa[1][i][j] = spa[1][i - 1][j] + spa[1][i - 1][spa[0][i - 1][j]];
		}
	}
}

ll query(ll u,ll v)
{
	if (u == v) return 0;
	if (depth[u] < depth[v])
		swap(u,v);
	ll ret = 0;
	for (ll i = LOG ; i >= 0 ; i--) if (depth[u] - (1 << i) >= depth[v])
	{
		ret += spa[1][i][u];
		u = spa[0][i][u];
	}
	if (u == v) return ret;
	for (ll i = LOG ; i >= 0 ; i--)
	{
		if (spa[0][i][u] != spa[0][i][v] && spa[0][i][u] != -1)
		{
			ret += spa[1][i][u];
			ret += spa[1][i][v];
			u = spa[0][i][u];
			v = spa[0][i][v];
		}
	}
	ret += spa[1][0][u];
	ret += spa[1][0][v];
	return ret;
}

void PreProcess()
{
	FindBridge();
	BuildBridgeTree();
	buildSparseTable();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 1 ; i <= m ; i++)
	{
		ll a,b,w;
		cin >> a >> b >> w;
		Graph_adj[a].push_back({b,w});
		Graph_adj[b].push_back({a,w});
	}
	PreProcess();
	ll queries;
	cin >> queries;
	while (queries--)
	{
		ll x,y;
		cin >> x >> y;
		x = prov[x];
		y = prov[y];
		cout << query(x,y) << endl;
	}
}