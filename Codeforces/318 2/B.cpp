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
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
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


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
//******************DELETE****************

int graph[4016][4016];

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,m;
    while(~getII(n,m))
    {
        int mark[n+4];
        CLR(graph);
        CLR(mark);
        for(int i=0;i<m;i++)
        {
            int x,y;
            getII(x,y);
            graph[x][y]=1;
            graph[y][x]=1;
            mark[x]++;
            mark[y]++;
        }
        int mini=INF;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(graph[i][j])
                {
                    for(int k=j+1;k<=n;k++)
                    {
                        if(graph[j][k] && graph[k][i])
                        {
                            int res=mark[i]+mark[j]+mark[k]-6;
                            mini=min(mini,res);
                        }
                    }
                }
            }
        }
        if(mini==INF) mini=-1;
        printf("%d\n",mini);
    }

    return 0;
}
