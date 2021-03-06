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
#define    pii 	 pair< ll, ll >
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

ll mod = 1000000007;

ll MOD(ll x)
{
    if(x<0) x += mod;
    return x%mod;
}

vector < pair<ll,int> > vp;

pii extendedEuclid(ll a, ll b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
        return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.ss, d.ff - d.ss * (a / b));
    }
}


int modularInverse(ll a, ll n)   	// returns a er modular Inverse ; n dara mod kore
{
    pii ret = extendedEuclid(a, n);
    return ((ret.ff % n) + n) % n;
}

#define minuss 1
#define pluss 0

int main()
{
#ifdef dipta007
    READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,k;
        getII(n,k);
        FOR(i,0,n-1)
        {
            ll x;
            getI(x);
            if(x<=0) vp.PB( MP(labs(x), minuss));
            else vp.PB( MP(x, pluss));
        }
        sort(ALLR(vp));

        int biog = 0;
        ll prev;
        ll res=1;
        ll lastPos=-1,lastNeg=1;
        FOR(i,0,k-1)
        {
            if(vp[i].ss==minuss)
            {
                biog++;
                lastNeg = -vp[i].ff;
                res = MOD( res * lastNeg );
            }
            else
            {
                lastPos = vp[i].ff;
                res = MOD( res * lastPos );
            }
        }

        ll nextPos = -1, nextNeg = 1;
        FOR(i,k,n-1)
        {
            if(vp[i].ss==minuss && nextNeg==1) nextNeg = -vp[i].ff;
            if(vp[i].ss==pluss && nextPos==-1) nextPos = vp[i].ff;

            if(nextPos!=-1 && nextNeg!=1) break;
        }

        ll finalAns=res;
        if(biog%2==1)
        {
            ll s1,s2;
            s1=s2=-INF;
            if(lastPos!=-1 && nextNeg!=1)
            {
                ll now = modularInverse(lastPos, mod);
                s1 = MOD( res * now );
                s1 = MOD( s1 * nextNeg );
            }
            if(lastNeg!=1 && nextPos!=-1)
            {
                ll now = modularInverse(lastNeg, mod);
                s2 = MOD( res * now );
                s2 = MOD( s2 * nextPos );
            }
            finalAns = max(s1,s2);


        }
        else
        {
            finalAns = res;
        }
    }

    return 0;
}



