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

vii adj;
vi dist;
int node,edge;
vi v;

int BFS(int src)
{
    map <int, int> mp;
    queue <int> q;
    mp[src]=1;
    q.push(src);

    while(!q.empty())
    {
        int u=q.front();
        //debug(u)
        q.pop();

        for(int j=0;j<v.size();j++)
        {
            int vv=u+v[j];
            if(vv<-2000 || vv>2000) continue;
            if(mp[vv]==0)
            {
                mp[vv]=mp[u]+1;
                q.push(vv);
                if(mp[vv]>3000) return -1;
            }
            else if(vv==0)
            {
                return mp[u];
            }
        }
    }
    return -1;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,k;
    while(~getII(n,k))
    {
        v.clear();
        int flg=0;
        int ff=0;
        FOR(i,0,k-1)
        {
            int x;
            getI(x);
            v.PB(x-n);

            if(x-n<=0) flg=1;
            if(x-n>=0) ff=1;
        }
        sort(ALL(v));
        UNIQUE(v);
//        v.erase(unique(v.begin(), v.end()), v.end());

//        adj.assign((int)v.size()+4, vi());
        node = v.size()+4;
//        FOR(i,0,2) debug(v[i])
//        debug(node)
//
//        FOR(i,0,(int)v.size()-1)
//        {
//            adj[0].PB(v[i]);
//        }
//
//        FOR(i,0,(int)v.size()-1)
//        {
//            FOR(j,0,(int)v.size()-1)
//            {
////                if(i==j) continue;
//                int u = v[i];
//                int vv = v[j];
//
//                adj[u].PB(u+vv);
////                adj[u].PB(u);
//            }
//        }
        int res;
        res = BFS(0);
        //res = -1;
        printf("%d\n",res);

    }


    return 0;
}



