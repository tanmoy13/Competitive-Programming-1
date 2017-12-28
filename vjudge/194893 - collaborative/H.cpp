#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

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
///****************** template ends here ****************
int t,n,m;

/// ********** FASTER one *******************///
namespace mf
{
    const int MAXN = 5016;
    struct edge {
        int a, b, cap, flow ;
        edge(int _a,int _b,int _c,int _d) {
            a=_a,b=_b,cap=_c,flow=_d;
        }
    } ;

    int INF = 1500000001 ;

    int n, s, t, d [ MAXN*2 ] , ptr [ MAXN*2 ] , q [ MAXN*2*10 ] ;
    vector < edge > e ;
    vector < int > g [ MAXN * 2 ] ;

    void addEdge ( int a, int b, int cap ,int cap2) {
        edge e1 =edge( a, b, cap, 0 ) ; /// forward cap
        edge e2 =edge( b, a, cap2 , 0 ) ; /// backward cap change here if needed
        g [ a ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e1 ) ;
        g [ b ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e2 ) ;
    }

    bool bfs ( ) {
        int qh = 0 , qt = 0 ;
        q [ qt ++ ] = s ;
        memset ( d, -1 , sizeof d ) ;
        d [ s ] = 0 ;
        while ( qh < qt && d [ t ] == - 1 ) {
            int v = q [ qh ++ ] ;
            for ( size_t i = 0 ; i < g [ v ] . size ( ) ; ++ i ) {
                int id = g [ v ] [ i ] ,
                    to = e [ id ] . b ;
                if ( d [ to ] == - 1 && e [ id ] . flow < e [ id ] . cap ) {
                    q [ qt ++ ] = to ;
                    d [ to ] = d [ v ] + 1 ;
                }
            }
        }
        return d [ t ] != - 1 ;
    }

    int dfs ( int v, int flow ) {
        if ( ! flow )  return 0 ;
        if ( v == t )  return flow ;
        for ( ; ptr [ v ] < ( int ) g [ v ] . size ( ) ; ++ ptr [ v ] ) {
            int id = g [ v ] [ ptr [ v ] ] ,
                to = e [ id ] . b ;
            if ( d [ to ] != d [ v ] + 1 )  continue ;
            int pushed = dfs ( to, min ( flow, e [ id ] . cap - e [ id ] . flow ) ) ;
            if ( pushed ) {
                e [ id ] . flow += pushed ;
                e [ id ^ 1 ] . flow -= pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }

    ll dinic ( ) {
        ll flow = 0 ;
        for ( ;; ) {
            if ( !bfs () )  break ;
            memset ( ptr, 0 , sizeof ptr ) ;
            while ( int pushed = dfs ( s, INF ) ) {
                flow += (ll)pushed ;
                if(pushed == 0)break;
            }
        }
        return flow ;
    }

    void init(int src, int dest , int nodes){
        e.clear();
        FOR(i,0,n+n) g[i].clear();
        n = nodes; s = src; t = dest;
    }
};


int main() {
    #ifdef dipta007
        READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

//    FOR(i,-1000,1000)
//    {
//        debug(i, exp(i), exp(i)==HUGE_VALF);
//    }
    int m,n,src,sink;
    while(~getII(m,n))
    {
        getII(src,sink);

        if(m==0 && n==0 && src==0 && sink==0) break;

        debug(m,n,src,sink)

        mf::init(0, n+1, n+4);

        mf::addEdge(0,src, 1000,0);
        mf::addEdge(sink, n+1, INF,0);

        FOR(i,1,m)
        {
            int u,v,w;
            double dw;
            getII(u,v);
            getF(dw);
            if(dw + EPS< -6.0) w = 0;
            else if(dw > -7+EPS && dw+EPS < 8)
            {
                dw = exp(dw);
                dw *= 1000.0;
                w = (int)(dw);
            }
            else if(dw > 7+EPS && dw+EPS<711)
            {
                w = 1000;
            }
            else w = 100000;

            debug(i, u, v, w);
            mf::addEdge(u,v,w,0);
        }

        ll kk = mf::dinic();
        debug(kk)
        if(kk >= 1000) printf("TRUE\n");
        else printf("FALSE\n");
    }

    return 0;
}


