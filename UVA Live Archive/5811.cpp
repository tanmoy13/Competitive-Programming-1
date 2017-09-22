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

int c,d,h,s;
bool vis[16][16][16][16][3][3][3][3];
double dp[16][16][16][16][3][3][3][3];

double call(int cc, int dd, int hh, int ss, int j1, int j2, int j3, int j4)
{
    if(cc>=c && dd>=d && hh>=h && ss>=s) return 0.0;

    //debug(cc,dd,hh,ss)
    double &ret = dp[cc][dd][hh][ss][j1][j2][j3][j4];
    if(vis[cc][dd][hh][ss][j1][j2][j3][j4]) return ret;
    vis[cc][dd][hh][ss][j1][j2][j3][j4]=1;

    ret = 0.0;

    int flg=0;
    /// a koita = ak
    double tot = 54 - cc - dd - hh - ss;
    double ck = 13-cc+j1;
    if(ck>0)
    {
        flg=1;
        ret += (ck/tot)*(1.0 + call(cc+1, dd, hh, ss, j1, j2, j3, j4));
    }

    double dk = 13-dd+j2;
    if(dk>0)
    {
        flg=1;
        ret += (dk/tot)*(1.0 + call(cc, dd+1, hh, ss, j1, j2, j3, j4));
    }

    double hk = 13-hh+j3;
    if(hk>0)
    {
        ret += (hk/tot)*(1.0 + call(cc, dd, hh+1, ss, j1, j2, j3, j4));
        flg=1;
    }

    double sk = 13-ss+j4;
    if(sk>0)
    {
        ret += (sk/tot)*(1.0 + call(cc, dd, hh, ss+1, j1, j2, j3, j4));
        flg=1;
    }

    double jk = 2-j1-j2-j3-j4;
    if(jk>0)
    {
        flg=1;
        double o1 = (jk/tot)*(1.0 + call(cc+1, dd, hh, ss, j1+1, j2, j3, j4));
        double o2 = (jk/tot)*(1.0 + call(cc, dd+1, hh, ss, j1, j2+1, j3, j4));
        double o3 = (jk/tot)*(1.0 + call(cc, dd, hh+1, ss, j1, j2, j3+1, j4));
        double o4 = (jk/tot)*(1.0 + call(cc, dd, hh, ss+1, j1, j2, j3, j4+1));

        ret += min(o1, min(o2, min(o3,o4)));
    }

    if(flg==0) return ret = INF;

    return ret;
}

int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        CLR(vis);
        getII(c,d);
        getII(h,s);

        double res = call(0,0,0,0,0,0,0,0);
        if(res>60) res=-1.0;
        printf("Case %d: %.3lf\n",ci,res);
    }

    return 0;
}




