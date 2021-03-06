#define NODE 100005
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<int> adj[NODE],scc[NODE];
int disc[NODE], low[NODE];
int vis[NODE];
int globalCnt = 0;
vector<int> tarjan;
int cycle[NODE];
int ans=0;

int SCC ( int s ) {
    vis[s] = GRAY;
    disc[s] = low[s] = globalCnt++;
    tarjan.push_back(s);

    for ( int i = 0; i < adj[s].size(); i++ ) {
        int t = adj[s][i];

        if ( vis[t] == WHITE ) {
            ///This is tree edge
            SCC ( t );
            low[s] = min ( low[s], low[t] );
        }
        else if ( vis[t] == GRAY ) {
            ///This is back edge
            ///Cycle detected
            low[s] = min ( low[s], low[t] );
        }
    }

    if ( disc[s] == low[s] ) {
            ans++;
        while ( 1 ) {
            int lastNode = tarjan.back();

            cycle[lastNode] = s;
            tarjan.pop_back();
            vis[lastNode] = BLACK;
            if ( lastNode == s ) break;
        }
    }

}
///call SCC with vis[s]==white
///call shrink with the tot node number
///remember this is 0 indexed
bool shrink(int node)
{
    repI(i,node)
    {
        repI(j,adj[i].size())
        {
            if(cycle[i]!=cycle[adj[i][j]])
            {
                scc[cycle[i]].push_back(cycle[adj[i][j]]);
            }
        }
    }
	///this inserts same edge multiple times
}
