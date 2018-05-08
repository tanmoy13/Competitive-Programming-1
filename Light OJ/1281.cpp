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

#ifdef dipta00
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

vector < pair < pii, int > > adj[10004];
int dist[12][10004];

int dj(int s, int d, int atMost)
{
    SET(dist);
    dist[0][s] = 0;
    priority_queue < pair < pii, int > , vector < pair < pii, int > >, greater < pair < pii, int > > > pq;

    /// distance, new road, node
    pq.push( MP( MP(0, 0), s));

    while(!pq.empty())
    {
        pair < pii, int > p = pq.top();
        pq.pop();

        int u = p.ss;
        int now =  p.ff.ff;
        int baki = p.ff.ss;

        debug(u, now, baki)
        if(u==d) return now;

        FOR(i, 0, (int)adj[u].size()-1)
        {
            pair < pii, int > q = adj[u][i];
            if(baki==atMost && q.ss) continue;

            int v = q.ff.ff;
            int w = q.ff.ss;
            int type = q.ss;
            debug("in", u, v, w, type)

            if(dist[baki+type][v]==-1)
            {
                debug("1st time", baki, type, v, dist[baki][u], w)
                dist[baki+type][v] = dist[baki][u] + w;
                pq.push( MP(MP(dist[baki+type][v], baki + type), v) );
            }
            else if(dist[baki+type][v] > dist[baki][u] + w)
            {
                debug("2")
                dist[baki+type][v] = dist[baki][u] + w;
                pq.push( MP(MP(dist[baki+type][v], baki + type), v) );
            }
        }
    }
    return -1;
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
        int n,m,k,d;
        getII(n,m);
        getII(k,d);

        repI(i,n+2) adj[i].clear();

        FOR(i,1,m)
        {
            int u,v,w;
            getIII(u,v,w);

            adj[u].PB(MP( MP(v,w) , 0 ));
        }
        FOR(i,1,k)
        {
            int u,v,w;
            getIII(u,v,w);

            adj[u].PB(MP( MP(v,w) , 1 ));
        }

        printf("Case %d: ",ci);
        int res = dj(0, n-1, d);
        if(res==-1) printf("Impossible\n");
        else printf("%d\n",res);
    }

    return 0;
}



