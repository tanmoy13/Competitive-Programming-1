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

int16_t adj[304][304][304];
vector < pii > vp;
bool vis[304][304][304];
int n,r,c;

// 4 direction
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int dfs(int x,int y,int tt)
{
    if(tt==n-1)
    {
        vp.PB(pii(x+1,y+1));
        return 1;
    }
    vis[tt][x][y]=1;
    FOR(i,0,3)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X>=0 && Y>=0 && X<r && Y<c && adj[tt+1][X][Y]==0 && vis[tt+1][X][Y]==0)
        {
            int k = dfs(X,Y,tt+1);
            if(k==1)
            {
                vp.PB(pii(x+1,y+1));
                return 1;
            }
        }
    }
    return 0;
}


int main() {
//    #ifdef dipta007
        READ("broadcast.in");
        WRITE("broadcast.out");
//    #endif // dipta007

    while(~getII(r,c))
    {
        CLR(adj);
        CLR(vis);
        vp.clear();
//        int n;
        getI(n);
        FOR(ik,0,n-1)
        {
            int x1,y1,x2,y2;
            getII(x1,y1);
            getII(x2,y2);
            x1--,x2--,y1--,y2--;
            FOR(i,x1,x2)
            {
                FOR(j,y1,y2)
                {
                    adj[ik][i][j]=1;
                }
            }
        }
        int flg=0;
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                if(adj[0][i][j]==0)
                {
                    int k = dfs(i,j,0);
                    if(k)
                    {
                        flg=1;
                        break;
                    }
                }
            }
            if(flg) break;
        }
        if(flg==0) printf("Impossible\n");
        if(flg)
        {
            ROF(i,(int)vp.size()-1,0)
            {
                printf("%d %d\n",vp[i].ff,vp[i].ss);
            }
        }
    }

    return 0;
}




