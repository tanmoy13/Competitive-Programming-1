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

#define SIZE 100004

int arr[SIZE];

struct node {
    int mini,maxy;
}tnode[4*SIZE];

void build ( int t, int l, int r ) {
    int m = ( l + r ) / 2;
    int u = t * 2;
    int v = u + 1;

    if ( l == r ) {
        /// This is a leaf
        tnode[t].mini = arr[l];
        tnode[t].maxy = arr[l];
        return;
    }

    build ( u, l, m );
    build ( v, m + 1, r );

    tnode[t].mini = min(tnode[u].mini, tnode[v].mini);
    tnode[t].maxy = max(tnode[u].maxy, tnode[v].maxy);

}

int queryRes, queryLeft, queryRight;
void query1 ( int t, int l, int r ) {
    int m = ( l + r ) / 2;
    int u = t * 2;
    int v = u + 1;

    if ( r < queryLeft || queryRight < l ) {
        ///Disjoint
        return;
    }

    if ( queryLeft <= l && r <= queryRight ) {
        queryRes = min(queryRes,tnode[t].mini);
        return;
    }

    query1 ( u, l, m );
    query1 ( v, m + 1, r );
}

void query2 ( int t, int l, int r ) {
    int m = ( l + r ) / 2;
    int u = t * 2;
    int v = u + 1;

    if ( r < queryLeft || queryRight < l ) {
        ///Disjoint
        return;
    }

    if ( queryLeft <= l && r <= queryRight ) {
        queryRes = max(queryRes,tnode[t].maxy);
        return;
    }

    query2 ( u, l, m );
    query2 ( v, m + 1, r );
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,d;
        getII(n,d);
        FOR(i,1,n)
        {
            getI(arr[i]);
        }
        build(1,1,n);
        int rmaxy = 0;
        for(int i=1;i<=n-d;i++)
        {
            queryLeft=i;
            queryRight=i+d-1;
            queryRes=INF;
            query1(1,1,n);
            int mini = queryRes;
            queryRes=0;
            query2(1,1,n);
            int maxy = queryRes;
            debug(i,i+d-1,mini,maxy)
            rmaxy = max(rmaxy, maxy-mini);
        }
        printf("Case %d: %d\n",ci,rmaxy);
    }

    return 0;
}



