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
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

/**
max flow (dinitz algorithm)
works on undirected graph
can have loops, multiple edges, cycles
**/


/**
*********   MUST be 1 indexed
*********   0 can not be a node
**/
namespace mf
{
    int src, snk, nNode, nEdge;
    const int MAXN = 104;
    const int MAXE = 20004; /// MAXE = twice the number of edges

    int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
    int flow[MAXE], cap[MAXE], nextt[MAXE], to[MAXE];

    inline void init(int _src, int _snk, int _n) {
        src = _src, snk = _snk, nNode = _n, nEdge = 0;
        SET(fin);
    }

    /// for directed graph _cap2 = 0
    inline void addEdge(int u, int v, int _cap, int _cap2) {
        to[nEdge] = v, cap[nEdge] = _cap, flow[nEdge] = 0;
        nextt[nEdge] = fin[u], fin[u] = nEdge++;
        to[nEdge] = u, cap[nEdge] = _cap2, flow[nEdge] = 0;
        nextt[nEdge] = fin[v], fin[v] = nEdge++;
    }

    bool bfs() {
        int st, en, i, u, v;
        SET(dist);
        dist[src] = st = en = 0;
        Q[en++] = src;
        while(st < en) {
            u = Q[st++];
            for(i=fin[u]; i>=0; i=nextt[i]) {
                v = to[i];
                if(flow[i] < cap[i] && dist[v]==-1) {
                    dist[v] = dist[u]+1;
                    Q[en++] = v;
                }
            }
        }
        return dist[snk]!=-1;
    }

    int dfs(int u, int fl) {
        if(u==snk) return fl;
        for(int &e=pro[u], v, df; e>=0; e=nextt[e]) {
            v = to[e];
            if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
                df = dfs(v, min(cap[e]-flow[e], fl));
                if(df>0) {
                    flow[e] += df;
                    flow[e^1] -= df;
                    return df;
                }
            }
        }
        return 0;
    }

    ll dinitz() {
        ll ret = 0;
        ll df;
        while(bfs()) {
            for(int i=1; i<=nNode; i++) pro[i] = fin[i];
            while(true) {
                df = dfs(src, INF);
                if(df) ret += df;
                else break;
            }
        }
        return ret;
    }
}



struct data
{
    int height,age,div;
};

bool check(data m, data f)
{
    if(abs(m.height - f.height) > 12) return false;
    if(abs(m.age - f.age) > 5) return false;
    if(m.div != f.div) return false;
    return true;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int m,n;
        getII(m,n);

        vector < data > male, female;
        FOR(i,1,m)
        {
            data d;
            getIII(d.height, d.age, d.div);
            male.PB(d);
        }
        FOR(i,1,n)
        {
            data d;
            getIII(d.height, d.age, d.div);
            female.PB(d);
        }

        mf::init(m+n+1,m+n+2,m+n+2);
        FOR(i,0,m-1)
        {
            FOR(j,0,n-1)
            {
                if(check(male[i], female[j]))
                {
                    mf::addEdge(i+1, m+j+1, 1, 0);
                }
            }
        }
        FOR(i,1,m) mf::addEdge(m+n+1, i, 1, 0);
        FOR(j,1,n) mf::addEdge(j+m, m+n+2, 1, 0);

        printf("Case %d: %lld\n",ci, mf::dinitz());

    }

    return 0;
}



