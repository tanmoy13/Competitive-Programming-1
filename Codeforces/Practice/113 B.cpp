#include <bits/stdc++.h>
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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out
/**
Procedure:
    1. Check SZ, mod, base, index of (base, mod)
    2. Create an object of Hashing
    3. Call makeForwardHashTable()
    4. Call makeBackwardHashTable() if needed
    5. For query call getForwardHashingQuery / getBackwardHashingQuery
**/
const int SZ = 1e5+4;
ll forwardHashTable[2][SZ];
ll backwardHashTable[2][SZ];
ll power[2][SZ];

class Hashing
{
    const long long mod[2] = {1000000007LL, 2117566807LL};
    const long long base[2] = {1572872831LL, 1971536491LL};
public:
    Hashing()
    {
        power[0][0]=1;
        power[1][0]=1;
        for(int i=0;i<2;i++)
        {
            for(int j=1;j<SZ;j++)
            {
                power[i][j] = (power[i][j-1] * base[i]) % mod[i];
            }
        }
    }

    ll MOD(ll x, int index)
    {
        return (x%mod[index]+mod[index])%mod[index];
    }

    void makeForwardHashTable(string st)
    {
        CLR(forwardHashTable);
        int len = st.size();

        for(int in=0; in<2; in++)
        {
            for(int i=0;i<len;i++)
            {
                int kk = st[i] - ' ';
                if(i)
                {
                    forwardHashTable[in][i] = ((forwardHashTable[in][i-1]*base[in])%mod[in] + kk)%mod[in];
                    continue;
                }
                forwardHashTable[in][i] = kk;
            }
        }
    }

    void makeBackwardHashTable(string st)
    {
        CLR(backwardHashTable);
        int len = st.size();
        for(int in=0; in<2; in++)
        {
            for(int i=len-1;i>=0;i--)
            {
                int kk = st[i] - ' ';
                if(i!=len-1)
                {
                    backwardHashTable[in][i] = ((backwardHashTable[in][i+1]*base[in])%mod[in] + kk)%mod[in];
                    continue;
                }
                backwardHashTable[in][i] = kk;
            }
        }
    }

    ll getForwardHashingQuery(int left, int right)
    {
        if(left==0)
        {
            return (forwardHashTable[0][right] << 31) | forwardHashTable[1][right];
        }
        ll ret1 = MOD(forwardHashTable[0][right] - (forwardHashTable[0][left-1] * power[0][right-left+1])%mod[0] , 0);
        ll ret2 = MOD(forwardHashTable[1][right] - (forwardHashTable[1][left-1] * power[1][right-left+1])%mod[1] , 1);
        ll ret = (ret1 << 31) | ret2;
        return ret;
    }

    ll getBackwardHashingQuery(int left, int right)
    {
        ll ret1 = MOD(backwardHashTable[0][left] - (backwardHashTable[0][right+1] * power[0][right-left+1])%mod[0] , 0);
        ll ret2 = MOD(backwardHashTable[1][left] - (backwardHashTable[1][right+1] * power[1][right-left+1])%mod[1] , 1);
        ll ret = (ret1 << 31) | ret2;
        return ret;
    }
};




int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    string st,s1,s2;
    while(cin >> st)
    {
        cin >> s1 >> s2;

        Hashing helper;
        helper.makeForwardHashTable(s1);
        ll h1 = helper.getForwardHashingQuery(0, s1.size()-1);
        helper.makeForwardHashTable(s2);
        ll h2 = helper.getForwardHashingQuery(0, s2.size()-1);

        vi v1,v2;
        int len = st.size();
        helper.makeForwardHashTable(st);
        FOR(i,0,len-s1.size())
        {
            ll now = helper.getForwardHashingQuery(i, i+s1.size()-1);
            if(now == h1) v1.PB(i);
        }
        FOR(i,0,len-s2.size())
        {
            ll now = helper.getForwardHashingQuery(i, i+s2.size()-1);
            if(now == h2) v2.PB(i);
        }

        ll res = 0;
        unordered_set < ll > s;
        FOR(i,0,(int)v1.size()-1)
        {
            auto l = lower_bound(ALL(v2), v1[i]) - v2.begin();
            FOR(j,l,(int)v2.size()-1)
            {
                if(v1[i] + s1.size() > v2[j] + s2.size()) continue;
                ll now = helper.getForwardHashingQuery(v1[i], v2[j]+s2.size()-1);
                debug(v1[i], v2[j]+s2.size()-1, now)
                s.insert(now);
            }
        }
        cout << s.size() << endl;
    }

    return 0;
}

