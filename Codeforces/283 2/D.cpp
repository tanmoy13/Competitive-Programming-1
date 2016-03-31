
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

int brk[]={1,6,1,2,2,3,1,4,0,1};

struct data
{
    int x,y;
};

bool operator<(const data &a, const data &b)
{
    if(a.x<b.x) return true;
    else if(a.x==b.x) return a.y<b.y;
    return false;
}

//bool cmp(const data &a,const data &b)
//{
//    if(a.x<b.x) return true;
//    else if(a.x==b.x) return a.y<b.y;
//    return false;
//}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    while(~getI(n))
    {
        int a[n];
        int c1=0,c2=0;
        vector <int> v1,v2;
        for(int i=0;i<n;i++)
        {
            getI(a[i]);
            if(a[i]==1)
            {
                c1++;
                v1.PB(i);
            }
            else
            {
                c2++;
                v2.PB(i);
            }
        }
        set <data> s;
        int maxy=0;
//        if(c1==c2)
//        {
//            printf("0\n");
//        }

        if(c2>c1)
        {
//            for(int i=1;i<v1.size();i++)
//            {
//                maxy=_max(maxy,v1[i]-v1[i-1]-1);
//            }
            for(int i=1;i<c2;i++)
            {
                if(c2%i==0)
                {
                    int k=c2/i;
                    data d;
                    if(i>c1)
                    {
                        d.x=k;
                        d.y=i;
                        s.insert(d);
                    }
                    if(k>c1)
                    {
                        d.x=i;
                        d.y=k;
                        s.insert(d);
                    }
                }
            }
        }
        else if(c1>c2)
        {
            for(int i=1;i<v2.size();i++)
            {
                maxy=_max(maxy,v2[i]-v2[i-1]-1);
            }
            for(int i=1;i<c1;i++)
            {
                if(c1%i==0)
                {
                    int k=c1/i;
                    data d;
                    if(i>c2)
                    {
                        d.x=k;
                        d.y=i;
                        s.insert(d);
                    }
                    if(k>c2)
                    {
                        d.x=i;
                        d.y=k;
                        s.insert(d);
                    }
                }
            }
        }
        printf("%d\n",s.size());
        FOREACH(i,s)
        {
            printf("%d %d\n",*i,*i);
        }
    }


    return 0;
}









