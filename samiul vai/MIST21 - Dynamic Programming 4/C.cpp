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

string dp[104][104];
int vis[104][104];
string s1,s2;

string call(int i,int j)
{
    if(i>=s1.size() || j>=s2.size()) return "";

    string &ret = dp[i][j];
    if(vis[i][j]==1) return ret;
    vis[i][j]=1;

    string o1,o2;
    if(s1[i]==s2[j])
    {
        ret = s1[i] + call(i+1,j+1);
        return ret;
    }
    else
    {
        o1 = call(i+1,j);
        o2 = call(i,j+1);
    }
    if(o1.size()>o2.size()) return ret=o1;
    else if(o2.size()>o1.size()) return ret=o2;
    else
    {
        return ret = min(o1,o2);
    }
}
//
//string res,lres;
//
//void print(int i,int j)
//{
//    if(i>=s1.size() || j>=s2.size())
//    {
//        if(lres.size()==0) lres=res;
//        else lres = min(lres,res);
//        //debug(lres,res)
//        return;
//    }
//
//    if(s1[i]==s2[j])
//    {
//        res += s1[i];
//        print(i+1,j+1);
//        res.erase(res.size()-1);
//    }
//    else
//    {
//        if(pri[i][j]==3)
//        {
//            print(i+1,j);
//            print(i,j+1);
//        }
//        else if(pri[i][j]==2)
//        {
//            print(i,j+1);
//        }
//        else
//        {
//            print(i+1,j);
//        }
//    }
//}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    getchar();
    FOR(ci,1,t)
    {
        getchar();
        getline(cin,s1);
        getline(cin,s2);

        CLR(vis);
        printf("Case %d: ",ci);
        string st = call(0,0);
        if(st.size()==0)
        {
            printf(":(\n");
            continue;
        }
        //debug("*")
        printf("%s\n",st.c_str());
    }

    return 0;
}



