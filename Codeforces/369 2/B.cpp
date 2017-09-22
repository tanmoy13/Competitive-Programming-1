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

ll a[504][504];
int n;

int check()
{
    set <ll> v;
    ll sum;
    FOR(i,0,n-1)
    {
        sum=0;
        FOR(j,0,n-1)
        {
            sum += a[i][j];
        }
        v.insert(sum);
    }
    FOR(j,0,n-1)
    {
        sum=0;
        FOR(i,0,n-1)
        {
            sum += a[i][j];
        }
        v.insert(sum);
    }
    sum=0;
    for(int i=0,j=0;i<n;i++,j++)
    {
        sum += a[i][j];
    }
    v.insert(sum);
    sum=0;
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        sum += a[i][j];
    }
    v.insert(sum);
    if(v.size()==1) return 1;
    return 0;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    while(~getI(n))
    {
        int x,y;
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                getL(a[i][j]);
                if(a[i][j]==0)
                {
                    x=i;
                    y=j;
                }
            }
        }

        if(n==1)
        {
            printf("1\n");
            continue;
        }
        set <ll> v;
        ll sum;
        FOR(i,0,x-1)
        {
            sum = 0;
            FOR(j,0,n-1)
            {
                sum += a[i][j];
            }
            v.insert(sum);
        }
        FOR(i,x+1,n-1)
        {
            sum=0;
            FOR(j,0,n-1)
            {
                sum += a[i][j];
            }
            v.insert(sum);
        }
        FOR(j,0,y-1)
        {
            sum=0;
            FOR(i,0,n-1)
            {
                sum += a[i][j];
            }
            v.insert(sum);
        }
        FOR(j,y+1,n-1)
        {
            sum=0;
            FOR(i,0,n-1)
            {
                sum += a[i][j];
            }
            v.insert(sum);
        }
        if(v.size()>1)
        {
            printf("-1\n");
            continue;
        }
        ll sr = 0;
        FOR(i,0,n-1)
        {
            sr += a[x][i];
        }
        ll sc=0;
        FOR(i,0,n-1)
        {
            sc += a[i][y];
        }
        if(sr!=sc)
        {
            printf("-1\n");
            continue;
        }
        ll res = *v.begin()-sr;
        if(res<=0)
        {
            printf("-1\n");
            continue;
        }
        a[x][y]=res;
        if(check()) printf("%lld\n",res);
        else printf("-1\n");
    }

    return 0;
}

