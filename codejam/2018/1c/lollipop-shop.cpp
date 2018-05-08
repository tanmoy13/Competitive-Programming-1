////#if !defined(YCM) && 1
////#define _FORTIFY_SOURCE 0
//#pragma GCC optimize("O3,Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
////#endif
//#include <unistd.h>
////#pragma GCC diagnostic ignored "-Wunused-result"
////#pragma GCC diagnostic ignored "-Wunused-function"
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb(a) push_back(a)
#define pii pair<int,int>
#define EPS 1e-9
#define PI acos(-1.0)
#define ff first
#define ss second
#define ALL(v) v.begin(),v.end()
int fx[]={0,0,-1,1,-1,1,1,-1};
int fy[]={1,-1,0,0,1,1,-1,-1};
ll lcm(ll a,ll b){return (a/__gcd(a,b))*b;}
ll bigmod(ll a,ll p,ll mod){ll ans=1;while(p){if(p&1)ans=ans*a%mod;a=a*a%mod;p>>=1;}return ans;}
ll power(ll x,ll n){if(n==0)return 1;else if(n%2==0){ll y=power(x,n/2);return y*y;}else return x*power(x,n-1);}
int biton(int n,int pos){return n=n | (1<<pos);}
int bitoff(int n,int pos){return n=n & ~(1<<pos);}
bool check(int n,int pos){return (bool)(n & (1<<pos));}
#ifdef shaft
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
const ll INF = (ll)1e18;
const int N=(int)1e3+1;
const int inf=(int)1e9;
const ll mod=(ll)1e9+7;
int mark[N], cnt[N], arr[N];
int main(){
    ios_base::sync_with_stdio(false);cout.setf(ios::fixed); cout.precision(10);cout.tie(nullptr); cin.tie(nullptr);
    #ifdef shaft
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif ///shaft
    srand(time(0));
    int t;
    cin >> t;
    while(t--){
        int n;
        CLR(mark); CLR(cnt);
        cin >> n;
        for(int i = 1; i <= n; i++){
            int d; cin >> d;
            vector<int>v;
            for(int j = 1; j <= d; j++){
                int x; cin >> x;
                arr[j] = x;
                if(mark[x]) continue;
                cnt[x] += 1;
            }
            int opt = inf;
            for(int j = 1; j <= d; j++){
                if(mark[arr[j]]) continue;
                if(cnt[arr[j]] < opt){
                    opt = cnt[arr[j]];
                    v.clear();v.pb(arr[j]);
                }
                else if(cnt[arr[j]] == opt)v.pb(arr[j]);
            }
            if(opt != inf){
                random_shuffle(ALL(v));
                int id = rand() % v.size();
                mark[v[id]] = 1;
                cout << v[id] << endl;
                cout . flush();
            }
            else{
                cout << -1 << endl;
                cout .flush();
            }
        }
    }
    return 0;
}

