//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int n, m, k;
vii dist;
vector < string > adj;

// 4 direction
int dxx[]={-1,1,0,0};
int dyy[]={0,0,-1,1};

int bfs(int sx, int sy, int dx, int dy, int flg)
{
    dist.assign(n, vi());
    FOR(i,0,n-1) dist[i].assign(m, INF);
    queue <int> q;
    if(flg == 0)
    {
        FOR(i,0,n-1) FOR(j,0,m-1) if(adj[i][j] == 'M')
        {
            q.push(i);
            q.push(j);
            trace(i, j);
            dist[i][j] = 0;
        }
    }
    else
    {
        q.push(sx);
        q.push(sy);
        dist[sx][sy] = 0;
    }
    while(!q.empty())
    {
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();
        trace(ux, uy);
        FOR(i,0,3)
        {
            int vx = ux + dxx[i];
            int vy = uy + dyy[i];

            if(vx >= 0 && vy >= 0 && vx < n && vy < m && adj[vx][vy] == '.')
            {
                if(dist[ux][uy] + 1 < dist[vx][vy])
                {
                    dist[vx][vy] = dist[ux][uy] + 1;
                    if(dist[vx][vy] <= k && flg == 0)
                    {
                        adj[vx][vy] = '#';
                    }
                    if(dist[vx][vy] < k && flg == 0)
                    {
                        q.push(vx);
                        q.push(vy);
                    }
                    else if(flg == 1)
                    {
                        q.push(vx);
                        q.push(vy);
                    }
                }
            }
        }
    }
    trace(sx, sy, dx, dy, dist[dx][dy]);
    return dist[dx][dy];
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin >> n >> m >> k)
    {
        adj.assign(n, "");
        int sx, sy, dx, dy;
        FOR(i,0,n-1)
        {
            cin >> adj[i];
            FOR(j,0,m-1)
            {
                if(adj[i][j] == 'S') sx = i, sy = j;
                else if(adj[i][j] == 'F') dx = i, dy = j;
            }
        }

        adj[dx][dy] = '.';
        adj[sx][sy] = '.';
        bfs(sx, sy, dx, dy, 0);
        if(adj[sx][sy] == '#' || adj[dx][dy] == '#')
        {
            cout << -1 << endl;
            continue;
        }
        int res = bfs(sx, sy, dx, dy, 1);
        if(res >= INF) res = -1;
        cout << res << endl;
    }

    return 0;
}

