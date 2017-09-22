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
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

#define princess 1
#define soldier 2
#define escape 3
#define blank 0
#define wall 4

int adj[204][204];
int dis[204][204];
int h,w;

// 4 direction
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
vector <pii> v;

int bfs(int sx,int sy)
{
    SET(dis);
    queue <int> q;
    q.push(sx);
    q.push(sy);
    dis[sx][sy]=0;
    int px,py;
    while(!q.empty())
    {
        int f=0;
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();
        FOR(i,0,3)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(vx>=0 && vy>=0 && vx<h && vy<w && dis[vx][vy]==-1 && adj[vx][vy]!=wall)
            {
                if(adj[vx][vy]==princess) px=vx,py=vy;
                dis[vx][vy] = dis[ux][uy]+1;
                q.push(vx);
                q.push(vy);
            }
        }
    }
    FOR(i,0,(int)v.size()-1)
    {
        pii p = v[i];
        if(dis[p.ff][p.ss]!=-1 && dis[p.ff][p.ss]<=dis[px][py])
        {
            return 0;
        }
    }
    return 1;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

//    int h,w;
    while(~getII(h,w))
    {
        v.clear();
        CLR(adj);
        getchar();
        int sx,sy;
        FOR(i,0,h-1)
        {
            string st;
            getline(cin,st);
            FOR(j,0,w-1)
            {
                if(st[j]=='@') adj[i][j]=princess;
                else if(st[j]=='$')
                {
                    v.PB(pii(i,j));
                    adj[i][j] = soldier;
                }
                else if(st[j]=='%')
                {
                    sx=i;
                    sy=j;
                    adj[i][j] = escape;
                }
                else if(st[j]=='#') adj[i][j] = wall;
            }
        }
        if(bfs(sx,sy)==1) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}


