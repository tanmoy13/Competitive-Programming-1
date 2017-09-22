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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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

int dist(pii a, pii b)
{
    return (a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss);
}


struct edge
{
    int u,v,w;
    edge()
    {

    }
    edge(int x,int y,int z)
    {
        u=x,v=y,w=z;
    }
    bool operator < (const edge &p) const
    {
        return w < p.w;
    }
};

class UnionFind
{
private:
    vi p,rank;
public:
    UnionFind(int n)

    {
        rank.assign(n+1,0);
        p.assign(n+1,0);
        for(int i=0; i<=n; i++)
            p[i]=i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i]=findSet(p[i]));
    }
    bool isSameSet(int i,int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i,int j)
    {
        if(!isSameSet(i,j))
        {
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y]) p[y]=x;
            else
            {
                p[x]=y;
                if(rank[x]==rank[y])
                    rank[y]++;
            }
        }
    }
};

vector <edge> e;
int stateNo;

pair <double, double> MST(int node, int r)
{
    sort(ALL(e));
    UnionFind uMst(node);

    double city=0.0,statee=0.0;
    int cnt=0,sum=0;
    for(int i=0;i<e.size();i++)
    {
        int x=uMst.findSet(e[i].u);
        int y=uMst.findSet(e[i].v);
        if(x!=y)
        {
            cnt++;
            uMst.unionSet(x,y);
            if(e[i].w>r)
            {
                statee += sqrt((double)e[i].w);
                stateNo ++;
            }
            else city += sqrt((double)e[i].w);
            if(cnt==node-1) break;
        }
    }
    return MP(city,statee);
}


int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,r;
        getII(n,r);
        vector <pii> vp;
        FOR(i,0,n-1)
        {
            int x,y;
            getII(x,y);
            vp.PB(pii(x,y));
        }

        e.clear();
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                if(i==j) continue;
                e.PB(edge(i,j,dist(vp[i],vp[j])));
            }
        }
        stateNo = 0;
        pair <double, double> p = MST(n,r*r);
        printf("Case #%d: %d %d %d\n",ci,stateNo+1,(int)round(p.ff),(int)round(p.ss));
    }

    return 0;
}





