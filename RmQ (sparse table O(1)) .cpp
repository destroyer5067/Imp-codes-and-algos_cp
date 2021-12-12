/*Range Minimum query using sparse table
o(1) approach*/



#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define FIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl ("\n")
#define ll  long long int
#define pii pair<ll,ll>
#define ff first
#define ss second
#define w(T) ll T;cin>>T;while(T--)
#define vi vector<ll>
#define vp vector<pair<ll,ll>>
#define vs vector<pair<ll,char>>
#define pb push_back
#define pf push_front
#define mp make_pair
#define sz(x) ((ll)(x).size())
#define f1(i,b) for(i=0;i<b;++i)
#define f(i,a,b) for(i=a;i<b;++i)
#define F(i,a,b) for(i=a;i>=b;--i)
#define rep(i,a,b) for(i=a;i<=b;++i)
#define sort(v) sort(v.begin(),v.end())
#define rev(v)  reverse(v.begin(),v.end())
#define mod 1000000007
#define mod2 998244353
#define INF 1e18

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}



ll tc = 0;

bool isPrime(ll n);
ll pw(ll x, ll y);
ll fact(ll n);
vi adj[200001];
// vi vis(200001, 0);
vi dis(200001, 0);
const ll N = 1e5 + 5;



const ll LOG = 20;
ll table[N][LOG];
ll bin_log[N];


void preprocess(ll n)
{

    bin_log[1] = 0;

    for (ll i = 2; i <= n; i++)
        bin_log[i] = bin_log[i / 2] + 1;


    for (ll j = 1; j < LOG; j++) {

        for (ll i = 0; i + (1 << j) - 1 < n; i++)
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);

    }
}

ll querymin(ll L, ll R) { // O(1)

    ll length = R - L + 1;
    ll k = bin_log[length];
    return min(table[L][k], table[R - (1 << k) + 1][k]);
}
void solve()
{

    map<ll, ll> m1, m2;
    string s1, s2, s3, s4, t;
    char ch1, ch2, ch3;
    ll n{}, v{}, m{}, k{}, i{}, j{}, x{}, y{}, z{}, u{}, l{}, h{}, p{}, q{}, w{}, o{}, r{}, s{}, a{}, b{}, c{}, d{}, e{}, sum{}, ans{}, ans2{10000000}, ans1{10000000};


    memset(table,0,sizeof(table));

    cin >> n;


    vi v1(n);

    f(i, 0, n) {

        cin >> v1[i];
        table[i][0] = v1[i];

    }

    preprocess(n);

   

    cin >> q;



    f(i, 0, q)
    {
        cin >> x >> y;
        cout << querymin(x,y) << endl;
    }


}


int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing 1output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    FIO


    // w(T) {

    //     tc++;
    //     solve();
    // }


    solve();
}

