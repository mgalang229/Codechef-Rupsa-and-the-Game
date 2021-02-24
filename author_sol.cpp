#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		n++;
		vector<int> a(n + 2);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int power_of_2 = 1;
		vector<int> suffix(1e5 + 10, 0);
		for (int i = n; i >= 1; i--) {
			suffix[i] = (1LL * a[i] * power_of_2) % mod;
			if (i < n) {
				suffix[i] = (suffix[i + 1] + suffix[i]) % mod;
			}
			power_of_2 = (power_of_2 * 2) % mod;
		}
		int ans = 0;
		power_of_2 = 1;
		for (int i = 1; i <= n; i++) {
			int count_ways = (1LL * power_of_2 * a[i]) % mod;
			count_ways = (1LL * count_ways * suffix[i + 1]) % mod;
			ans = (ans + count_ways) % mod;
			if (i >= 2) {
				power_of_2 = (power_of_2 * 2) % mod;
			}
		}
		cout << (2 * ans) % mod << '\n';
	}
	return 0;
}
