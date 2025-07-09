#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define acc accumulate
#define eb emplace_back
#define pb push_back
#define ms multiset
#define fon for(ll i=0;i<n;i++)
#define fr(j,x,y) for (ll j=x;j<y;j++)
#define ln '\n'
#define db double
#define all(v) v.begin(),v.end()
#define f first
#define s second
#define stg string
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define dq deque
#define pf push_front
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<string> vs;

//oeis.org for sequences

//1 << k = 2^k
//n%2^k = n&((1<<k)-1)

// bool isBitSet(ll n, ll k) { return n & (1 << k); }
// bool powerof2(ll a) { return a and !(a & (a-1)); }
// void toggleBit(ll &n, ll k) {n ^ (1 << k); }
// void setBit(ll &n, ll k) { n | (1 << k);}
// void unsetBit(ll &n , ll k) {n & ~(1 << k);}
ll gcd(ll a,ll b) { if (a == 0ll) return b; return gcd(b%a, a); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll ceilDiv(ll a, ll b) { return a%b == 0 ? a/b : a/b + 1;}
vl makev(ll n) {vl v(n); fon cin >> v[i]; return v;}
// bool isPrime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
const int MOD = 1e9+7;

// vector<ll> sieve(ll n) {
// 	vector<bool> v(n+1, true);
// 	vector<ll> ans;
// 	v[0] = v[1] = false;
	
// 	for (ll i = 2; i <= n; i++) {
// 		if (v[i]) {
// 			ans.eb(i);
// 			for (ll j = i*i; j < n+1; j += i) {
// 				v[j] = false;  
// 			}
// 		}
// 	}
// 	return ans;
// }

//oeis.org for sequences

template <class T>
void printv(vector<T> &v) { 
    for (auto x : v) cout << x << " "; 
    cout << ln;
}

// stg to_lower(stg s) {
//     ll n = s.size();
//     fon {
//         if (s[i] >= 'A' and s[i] <= 'Z') {
//             s[i] = s[i] - 'A' + 'a';
//         }
//     }
//     return s;
// }

// ll mod (ll a, ll b) {return a < 0 ? (a%b) + b : a%b;}

ll power(ll a, ll b) {
    if (b == 0) return 1;
    ll half = power(a,b/2);
    if (b&1) return (half * half * (a%MOD)) % MOD;
    else return (half * half) % MOD;
}

// vector<pll> sort_freq_map(map<ll, ll> m) { //sorts map based on frequency, ascending
//     vector<pll> v(m.begin(), m.end());
//     sort(all(v), [](pll a, pll b) {
//         return a.s < b.s;
//     });
//     return v;
// }

// ll slidingWindow(ll n, ll k, vl v) {
//     ll sum = 0;
//     for (ll i = 0; i < k; i++) {
//         sum += v[i];
//     }

//     ll maxSum = sum;

//     for (ll i = k; i < n; i++) {
//         sum += v[i];
//         sum -= v[i-k];

//         maxSum = max(maxSum, sum);
//     } 

//     return maxSum;
// }

// struct FenwickTreeOneBasedIndexing {
//     vector<int> bit;  // binary indexed tree
//     int n;

//     FenwickTreeOneBasedIndexing(int n) {
//         this->n = n + 1;
//         bit.assign(n + 1, 0);
//     }

//     FenwickTreeOneBasedIndexing(vector<int> a)
//         : FenwickTreeOneBasedIndexing(a.size()) {
//         for (size_t i = 0; i < a.size(); i++)
//             add(i, a[i]);
//     }

//     int sum(int idx) {
//         int ret = 0;
//         for (++idx; idx > 0; idx -= idx & -idx)
//             ret += bit[idx];
//         return ret;
//     }

//     int sum(int l, int r) {
//         return sum(r) - sum(l - 1);
//     }

//     void add(int idx, int delta) {
//         for (++idx; idx < n; idx += idx & -idx)
//             bit[idx] += delta;
//     }
// };

bool isSubstring(const string &a, const string &b) {
    return a.find(b) != string::npos; // is b present in a
}

void solve() {
    int n,q;
    cin >> n >> q;
    vl v(n);
    vl vq(q);

    fon cin >> v[i];
    fr (i,0,q) cin >> vq[i];

    fr (i,0,q) {
        fr (j,0,n) {
            if ((v[j] & ((1 << vq[i]) - 1)) == 0) {
                v[j] += (1 << (vq[i]-1));
                j--;
            }
        }
    }

    printv(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}

// ll n;
// cin >> n;

// vl v(n);
// fon cin >> v[i];

// if (n==1) {
//     cout << v[0] << ln;
//     return;
// }
// if (n==3) {
//     cout << max(max(v[0]+1, v[1]), v[2]+1) << ln;
//     return;
// }

// ll ans = *max_element(all(v));

// ans += (n-5)/2 + 2;

// cout << ans << ln;