#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
vector<int> leftSide;
int N , M  ; // N = Number of Nodes on the Left side and M = Number of Edges in the bipartite graph
vector<int> g [ MAXN ] ; // Declaration of our bipartite graph
int Distance[ MAXN ] ; // This will store the Length of augmenting path we have made till this node
int matched[ MAXN ] ; // matched[u] = v , if there is an edge between u and v in final matched graph.
const int INF = 1e9 ;

void reset()
{
  leftSide.clear();
  for (int i = 1 ; i <= MAXN ; i++)
    g[i].clear();
  memset(Distance,0,sizeof(Distance));
  memset(matched,0,sizeof(matched));
}

bool bfs( )
 {
    /**
       Construction of Layered graph with alternating matched and unmatched edges using bfs.
    **/
    queue<int> q ;
    for( int i = 0 ; i < N ; i ++ )  // Looping through all Left Side vertices
        if( matched[leftSide[i]] == 0 ) // If this vertex is not matched then insert it into queue to make layered graph
          {  q.push(leftSide[i]) ;
             Distance[leftSide[i]] = 0 ;
          }
        else Distance[leftSide[i]] = INF ; // it is matched we dont have to consider it now

     Distance[0] = INF ; // This is the dummy vertex created to check existence of a augmenting path if this remains INF  after bfs then it would mean that there are
                   // no more augmenting paths and we need to stop now
     while( !q.empty() )
      {
          int Left = q.front( ); // unmatched vertex
          q.pop() ;
          for( int Right : g[Left] )  // Looking for all right side vertices
            {
               if( Distance[ matched[Right] ] == INF ) // This means that the edge between ch and matched[ch]  is a matched edge and hence fulfils our condition of alterating vertices
                 {
                      Distance[ matched[Right] ] = Distance[Left] + 1 ; // We made  it an unmatched edge and pushed into the queue
                      q.push( matched[Right] ) ;
                 }

            }

      }

     return ( Distance[ 0  ] != INF )  ; // if Distance is not equal to infinity then we have find an augmenting path and it will increasing matching by atleast one.

 }

/* Construction of new matching using dfs */
bool dfs(  int Left )
 {
    if( Left == 0 )return true ;

    for( int Right : g[Left] )
      {
         if(  Distance[matched[Right]] == Distance[Left] + 1  )
               if( dfs( matched[Right] ) )
                 {
                    matched[Left] = Right ;
                    matched[Right] = Left ;
                    return true ;
                 }

      }

      Distance[ Left ] = INF ;
      return false ;

 }

int Hopcroft( )
 {
     int matching = 0 ;

     while( bfs( ) )
      {
         for(  int i = 0 ; i < N ; i ++ )
              if( matched[leftSide[i]] == 0 and dfs(  leftSide[i] ) ) // updating the matched and unmatched vertices
                       matching++ ;  // Since every augmenting path increases matching by 1
      }
      return matching;
      // cout<<matching<<endl;

 }

struct data
{
    int w;
    int l;
    int h;
};

data tab[510];

int main( )
 {
    // int B ;
    // scanf("%d%d%d",&N,&B,&M) ;
    // FOR( i , M )
    //   {
    //       int u , v ;
    //       scanf("%d%d",&u,&v) ;
    //       v =  v + N  ;
    //       g[u].pb( v ) ;
    //       g[v].pb( u ) ;

    //   }

    // Hopcroft( ) ;
  int n;
  int t;
  cin >> t;
  while (t--)
  {
      cin >> n;
      reset();
      for (int i = 1 ; i <= n ; i++)
        cin >> tab[i].w >> tab[i].l >> tab[i].h;
      for (int i = 1 ; i <= n ; i++)
        for (int j = i + 1 ; j <= n ; j++)
        {
            if (tab[i].w < tab[j].w && tab[i].l < tab[j].l && tab[i].h < tab[j].h)
            {
                leftSide.push_back(i);
                g[i].push_back(j + n);
                g[j + n].push_back(i);              
            }
            if (tab[i].w > tab[j].w && tab[i].l > tab[j].l && tab[i].h > tab[j].h)
            {
                leftSide.push_back(j);
                g[i + n].push_back(j);
                g[j].push_back(i + n); 
            }
        }   
      N = leftSide.size();
      int ans = n - Hopcroft();
      cout << ans << endl;
  }
 }