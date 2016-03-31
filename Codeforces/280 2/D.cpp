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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%I64d",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }


#define van 1
#define vo 2
#define both 3

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,x,y;
    while(~getIII(n,x,y))
    {
        ll lc=lcm((ll)x,(ll)y);
        //debug(lc);
        int xx=x,yy=y;
        int mot=x+y;
        x=lc/x;
        y=lc/y;
        int maxy=-1;
        int a[n];
        for(int i=0;i<n;i++)
        {
            getI(a[i]);
            maxy=_max(maxy,a[i]);
        }
        if(x==y)
        {
            for(int i=0;i<n;i++)
            {
                printf("Both\n");
            }
            continue;
        }
        int hx=x,hy=y;
        int dp[maxy+4];
        int mod;
        for(int i=1;i<=maxy;i++)
        {
            if(hx<hy)
            {
                dp[i]=1;
                hx+=x;
            }
            else if(hy<hx)
            {
                dp[i]=2;
                hy+=y;
            }
            else
            {
                dp[i]=3;
                hx+=x;
                hy+=y;
                mod=i;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            int k=a[i]%mod;
            int l=a[i]/mot;
            if()
            if(k==0) k=mod;
            if(dp[k]==1)
            {
                int l=a[i]-xx;
                printf("Vanya\n");
            }
            else if(dp[k]==2)
            {
                printf("Vova\n");
            }
            else
            {
                printf("Both\n");
            }
        }
    }

    return 0;
}








