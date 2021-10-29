#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}
 
const int N = 5050;
int C[N][N];
int dp[N];
int n, m;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
	scanf("%d%d", &n, &m);
 
	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	for (int k = 2; k <= n; k += 2)
		dp[k] = C[n][k];
	for (int x = 2; x < m; x += 2)
		for (int k = 0; 2 * x + k <= m && k <= n; k += 2){
			printf("dp[%d] adds with dp[%d] * C(%d, %d)\n", 2 * x + k, x, n, k);
            dp[2 * x + k] = add(dp[2 * x + k], mult(dp[x], C[n][k]));
        }
	printf("%d\n", dp[m]);
 
	return 0;
}
