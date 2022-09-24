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

void run_case()
{
	ll n;
	cin >> n;
	vector<ll> v(4, 0);
	for (ll i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		v[x]++;
	}
	double dp[n + 1][n + 1][n + 1] = {0};
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= n; j++)
		{
			for (ll k = 0; k <= n; k++)
			{
				ll x = n - i - j - k;
				if (x == n)
					continue;
				if (i + j + k > n)
					continue;
				double val = 1.0;
				if (i > 0)
					val += ((1.0 * i) / n) * dp[i - 1][j + 1][k];
				if (j > 0)
					val += ((1.0 * j) / n) * dp[i][j - 1][k + 1];
				if (k > 0)
					val += ((1.0 * k) / n) * dp[i][j][k - 1];
				val /= (1.0 - (1.0 * x) / n);
				dp[i][j][k] = val;
			}
		}
	}
	double ans = dp[v[3]][v[2]][v[1]];
	prDouble(ans, 14) << nl;
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