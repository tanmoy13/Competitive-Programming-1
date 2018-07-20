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

int mark[1004][1004][10];


// 8 direction

///        0  1   2   3    4   5   6   7
int dx[]={-1, 1,  0,  0,  -1, -1,  1,  1};
int dy[]={ 0, 0, -1,  1,  -1,  1,  1, -1};


vi adj[10];
int n;

int a[34];

bool dp[34][304][304][8];

pii dfs(int x, int y, int kk, int moves)
{
    mark[x][y][kk] = moves+1;
    if(moves == 0) return pii(x,y);
    return dfs(x+dx[kk], y+dy[kk], kk, moves-1);
}

void call(int in, int x, int y, int flg)
{
//    debug(in, x, y, flg, adj[flg].size())

    if(dp[in][x][y][flg]) return;
    dp[in][x][y][flg] = 1;

    if(in >= n) return;
    for(auto v: adj[flg])
    {
        pii p = dfs(x, y, v, a[in]);
//        debug(in, x, y, p.ff, p.ss, flg, "->", v)
        if(p.ff != -1) call(in+1, p.ff, p.ss, v);
    }
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    adj[0].PB(4);
    adj[0].PB(5);

    adj[1].PB(7);
    adj[1].PB(6);

    adj[2].PB(7);
    adj[2].PB(4);

    adj[3].PB(6);
    adj[3].PB(5);

    adj[4].PB(2);
    adj[4].PB(0);

    adj[5].PB(0);
    adj[5].PB(3);

    adj[6].PB(1);
    adj[6].PB(3);

    adj[7].PB(2);
    adj[7].PB(1);

//    int n;
    while(~getI(n))
    {
        pii p;
        CLR(mark);
        int x = 150, y = 150;
        FOR(i,0,n-1)
        {
            getI(a[i]);
            if(i==0) p = dfs(x,y, 1, a[i]);
        }

        debug(p.ff, p.ss)
        CLR(dp);
        mark[p.ff][p.ss][1] = 0;
        call(1, p.ff-1, p.ss, 1);


        int cnt = 0;
        FOR(i,0,300)
        {
            FOR(j,0,300)
            {
                int flg = 0;
                FOR(k,0,7) flg = flg || ( mark[i][j][k] != 0 );
                cnt += flg;
//                if(mark[i][j] == 0) cout << "  ";
//                else cout << mark[i][j] << " ";
            }
//            cout << endl;
        }

        printf("%d\n", cnt);
    }


    return 0;
}
