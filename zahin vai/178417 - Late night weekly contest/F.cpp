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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

int *lps;
void computeLPSArray(string pat, int M, int *lps);

bool KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    while(i < N)
    {
        if(pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            return true;
            j = lps[j-1];
        }

        // mismatch after j matches
        else if(pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if(j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    free(lps); // to avoid memory leak
    return false;
}

void computeLPSArray(string pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if( len != 0 )
            {
                // This is tricky. Consider the example AAACAAAA and i = 7.
                len = lps[len-1];

                // Also, note that we do not increment i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }

//    /// LPS array print
//    cout << "LPS array" << endl;
//    for(int i=0; i<M; i++)
//    {
//        cout << pat[i] << " " << lps[i] << endl;
//    }
}

string mst,ans;

//string call(string st)
//{
//    FOR(i,0,25)
//    {
//        st += (char)(i+'a');
//        if(!KMPSearch(st)) return st;
//    }
//
//    FOR(i,0,25)
//    {
//        st += (char)(i+'a');
//    }
//}

bool call(int in, string st)
{
    if(in==0 && !KMPSearch(st, mst))
    {
        ans = st;
        return true;
    }
    else if(in==0) return false;

    FOR(i,0,25)
    {
        int kk = call(in-1, st + (char)(i+'a'));
        if(kk) return true;
    }
    return false;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(cin >> n)
    {
        mst = "";
        FOR(i,1,n)
        {
            string st;
            cin >> st;
            mst += st;
            mst += "#";
        }

        FOR(i,1,601)
        {
            if(call(i, ""))
            {
                cout << ans << endl;
                break;
            }
        }
//
//        debug(mst)
//        vector < string> vs;
//
//        int flg = 0;
//        FOR(i,0,25)
//        {
//            string tmp = "";
//            tmp += (char)(i + 'a');
//            debug(tmp)
//            if(!KMPSearch(tmp, mst))
//            {
//                cout << tmp << endl;
//                flg = 1;
//                break;
//            }
//            vs.PB(tmp);
//        }
//
//        FOR(i,1,100)
//        {
//            if(flg) break;
//            FOR(j,0,25)
//            {
//                string tmp = vs[j] + (char)(j + 'a');
//                debug(tmp)
//                if(!KMPSearch(tmp, mst))
//                {
//                    cout << tmp << endl;
//                    flg = 1;
//                    break;
//                }
//                vs[j] = tmp;
//            }
//        }

    }

    return 0;
}



