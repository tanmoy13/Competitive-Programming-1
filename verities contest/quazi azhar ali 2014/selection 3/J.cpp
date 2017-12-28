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
#define    getL(n)           scanf("%lld",&n)
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


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    ll n;
    while(~getL(n))
    {
        if(n==0) break;

        ll c1,c2,n1,n2;
        getL(c1);
        getL(n1);
        getL(c2);
        getL(n2);

        ll fst,scnd,flg=1;
        double av1=(double)c1/n1;
        double av2=(double)c2/n2;
        debug(av1);
        debug(av2);
        if(av1+EPS<=av2)
        {
            debugI();
//            debug(n1);
            ll k=n%n1;
//            debug(k);
            if(k<n2 && k!=0)
            {
                k=k+n1;
            }
//            debug(k);
            if(k%n2==0)
            {
//                debugII();
                scnd=k/n2;
                fst=(n-k)/n1;
            }
            else
            {
//                debugIII();
                ll k=n%n2;
                if(k<n1 && k!=0)
                {
                    k+=n2;
                }
                if(k%n1==0)
                {
                    fst=k/n1;
                    scnd=(n-k)/n2;
                }
                else flg=0;
            }
        }
        else
        {
            ll k=n%n2;
            if(k<n1 && k!=0)
            {
                k=k+n2;
            }
            if(k%n1==0)
            {
                fst=k/n1;
                scnd=(n-k)/n2;
            }
            else
            {
                ll k=n%n1;
                if(k<n2 && k!=0)
                {
                    k+=n1;
                }
                if(k%n2==0)
                {
                    scnd=k/n2;
                    fst=(n-k)/n1;
                }
                else flg=0;
            }
        }
        if(flg==1) printf("%lld %lld\n",fst,scnd);
        else printf("failed\n");
    }

    return 0;
}
