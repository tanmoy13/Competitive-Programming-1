#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

const int MX = 504;
int grid[MX][MX];
int dist[MX][MX],visited[MX][MX];
int spe[MX][MX];
int row,col;

int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};

struct point
{
    int x,y;
    point()
    {

    }
    point(int a,int b)
    {
        x=a,y=b;
    }
};

int BFS2d(point src,point dest)
{
    CLR(visited);
    SET(dist);
    dist[src.x][src.y]=0;
    visited[src.x][src.y]=1;
    queue <point> q;
    q.push(src);

    while(!q.empty())
    {
        point u=q.front();
        debug(u.x,u.y)
        q.pop();
        for(int i=0; i<4; i++)
        {
            int X=u.x+dx[i];
            int Y=u.y+dy[i];
            if(X>=0 && X<row && Y>=0 && Y<col && visited[X][Y]==0 && grid[X][Y]==0)
            {
                visited[X][Y]=1;
                dist[X][Y]=dist[u.x][u.y]+1;
                q.push(point(X,Y));
            }
        }
    }
    return dist[dest.x][dest.y];
}


int BFS2d1(point src,point dest)
{
    CLR(visited);
    SET(dist);
    dist[src.x][src.y]=0;
    visited[src.x][src.y]=1;
    queue <point> q;
    q.push(src);

    while(!q.empty())
    {
        point u=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int X=u.x+dx[i];
            int Y=u.y+dy[i];
            if(X>=0 && X<row && Y>=0 && Y<col && visited[X][Y]==0)
            {
                if(grid[X][Y]==0)
                {
                    visited[X][Y]=1;
                    dist[X][Y]=dist[u.x][u.y]+1;
                    q.push(point(X,Y));
                }
                else if(spe[X][Y]==2)
                {
                    visited[X][Y]=1;
                    dist[X][Y]=dist[u.x][u.y]+1;
                    q.push(point(X,Y));
                }
            }
        }
    }
    return dist[dest.x][dest.y];
}


int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int k;
    while(~getIII(row, col, k))
    {
        getchar();
        CLR(spe);

        FOR(i,0,row-1)
        {
            string st;
            getline(cin,st);
            debug(st);
            FOR(j,0,col-1)
            {
                if(st[j]=='.') grid[i][j]=0;
                else grid[i][j]=1;
            }
        }
        FOR(i,0,k-1)
        {
            int x,y;
            getII(x,y);
            spe[x][y]=2;
        }
        int n=row, m = col;
        int mar = BFS2d(point(0, 0), point(n-1, m-1));
        int ami = BFS2d1(point(0, 0), point(n-1, m-1));
        debug(mar, ami)
        if(ami==-1) printf("NO\n");
        else if(mar==-1) printf("YES\n");
        else
        {
            if(ami+5 < mar) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}



