#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second

#define all(x) (x).begin(), (x).end()
#define prDouble(x,y) cout << fixed << setprecision(y) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fast_io2 cin.exceptions(cin.failbit);
#define M 1000000007
#define inf 1000000000000000005
#define MOD 998244353
#define nl endl

using namespace std;
using namespace __gnu_pbds;

template <class T> using maxheap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T, class V = less<T>> using pbds = tree<T, null_type, V, rb_tree_tag, tree_order_statistics_node_update>; //find_by_order, order_of_key

/*-------------------------------------------------------------------------------------------------------------------------------------*/

void google_case(ll i){cout<<"Case #"<<i<<": ";}
ll inv(ll i) {if (i == 1) return 1; return (M - ((M / i) * inv(M % i)) % M) % M;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}//O(sqrt(N))
bool isPrime(ll n){if (n <= 1) return false; for (ll i = 2; i < n; i++)if (n % i == 0) return false; return true;}
ll fast_mul(ll x, ll y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------*/

ll dp[404][404];
ll get_sum(vector<ll> &pre, ll i, ll j)
{
    ll temp1 = i == 0 ? 0 : pre[i - 1];
    ll temp2 = pre[j];
    ll ans = temp2 - temp1;
    return ans;
}
ll solve(ll i, ll j, vector<ll> &pre, ll sum)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = inf;
    for (ll k = i; k < j; k++)
    {
        ll sum1 = get_sum(pre, i, k);
        ll sum2 = get_sum(pre, k + 1, j);
        ll op1 = solve(i, k, pre, sum1);
        ll op2 = solve(k + 1, j, pre, sum2);
        ll temp = sum + op1 + op2;
        ans = min(ans, temp);
    }
    dp[i][j] = ans;
    return ans;
}
void run_case()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    vector<ll> pre(n);
    for (ll i = 0; i < n; i++)
        pre[i] = (i == 0 ? 0 : pre[i - 1]) + v[i];
    memset(dp, -1, sizeof(dp));
    ll ans = solve(0, n - 1, pre, pre[n - 1]);
    cout << ans << nl;
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        // google_case(i);
        run_case();
    }
    return 0;
}