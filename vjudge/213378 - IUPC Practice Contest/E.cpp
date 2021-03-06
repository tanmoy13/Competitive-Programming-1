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

#define dipta00
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

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

vii adj;
int vis[10004][104];
int dp[10004][104];
vi v;

int callP(int in, int p, int m)//, int v1, int v2)
{
    if(in >= v.size()) return 0;

    int &ret = dp[in][p];
    if(ret != -1) return ret;

    if(v[in] >= 10)
    {
        ret = max(ret , v1 + v2 )
    }
}

int callM(int in, int p, int m)
{
    if(vis[in][m] == 1) return dp[in][m];
    vis[in][m] == 1;

    if(adj[in].size() == 2)
    {
        int o1, o2;
        if(p > 0) o1 = callM(adj[in][0], p-1, m) + callM(adj[in][1], p-1, m);
        if(m > 0) o2 = callM(adj[in][0], p, m-1) - callM(adj[in][1], p, m-1);
        return dp[in][m] = max(o1, o2);
    }
    else if(adj[in].size() == 1)
    {
        return dp[in][m] = adj[in][0];
    }
    else return dp[in][m] = in;
}

void post(int in)
{
    for(auto v: adj[in]) post(v);
    v.PB(in);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    string st;
    while ( cin >> st )
    {
        adj.assign(10000, vi());

        st = st;

        int node = 10;
        stack < int > nodes, s;
        FOR(i,0,(int)st.size()-1)
        {
            if(st[i] == ')')
            {
                 if(s.size() >= 2)
                 {
                     int a = s.top(); s.pop();
                     int b = s.top(); s.pop();
                     adj[node].PB(b);
                     adj[node].PB(a);

                     nodes.push(node);

                     node++;
                 }
                 else if(s.size() == 1)
                 {
                     int na = nodes.top(); nodes.pop();
                     int b = s.top(); s.pop();

                     adj[node].PB(b);
                     int nb = node;

                     node++;

                     adj[node].PB(na);
                     adj[node].PB(nb);

                     nodes.push(node);

                     node++;
                 }
                 else
                 {
                     int na = nodes.top(); nodes.pop();
                     int nb = nodes.top(); nodes.pop();

                     adj[node].PB(nb);
                     adj[node].PB(na);

                     nodes.push(node);

                     node++;
                 }
            }
            else if(st[i] >= '0' && st[i] <= '9')
            {
                int kk = st[i] - '0';
                s.push(kk);
            }
        }

        FOR(i,0,node-1)
        {
            cout << i << " : ";
            for(auto v: adj[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }

        v.clear();
        post(node-1);

        int p, m;
        cin >> p >> m;
        int res;
        CLR(vis);
        if(p <= m)
        {
            res = callP(node-1, p, m);
        }
        else
        {
            res = callM(node-1, p, m);
        }
        cout << res << endl;
    }


    return 0;
}

