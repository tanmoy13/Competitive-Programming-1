#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)

#define    m_p(x, y)         make_pair(x, y)
#define    p_b(x)             push_back(x)

#define    rep(i,n)         for(int i=1;i<=n;i++)
#define    rep0(i,n)         for(int i=0;i<n;i++)


#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int



template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }


//******************DELETE****************

#ifdef rafsan_rana
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


int bitOn(int N,int pos)
{
    return N=N | (1<<pos);
}
int bitOff(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool bitCheck(int N,int pos)
{
    return (bool)(N & (1<<pos));
}



///*******************************************************************************************






int main()
{



#ifdef rafsan_rana

    // READ("in.txt");
    // WRITE("out.txt");

#endif // rafsan_rana

    ios_base::sync_with_stdio(0);  cin.tie(0);

    int n;
    while(cin>>n)
    {
        int a[n];
        int b[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=1;
        }

        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1]) b[i]=b[i-1]+1;
        }

        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>a[i+1])
            {
                if(b[i]<=b[i+1])
                {
                    b[i]=b[i+1]+1;
                }
            }
        }

        long long cc=0;

        for(int i=0;i<n;i++) cc+=b[i];

        cout<<cc<<endl;


    }




    return 0;
}
