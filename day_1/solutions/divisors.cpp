#include <bits/stdc++.h>
using namespace std;

#define MAXN 512
#define MAXINST 12000

#if 0
bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}
vector<char> sieve;
void build_sieve(int N) {
	for (int i = 2; i<N; i++) {
		if (is_prime(i)) {
			for (int j = i * i; j < N; j+=i) {
				sieve[j] = false;	
			}
		}
	}
}

inline bool is_prime_fast(int n) {
	return sieve[n];
}
#endif

char sieve[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1};

inline bool is_prime_fast(int n) {
	return sieve[n];
}

int primes_map[MAXINST][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	int it = 0;
	while (cin >> n >> k) {
		if (k == 0) {
			cout << 1 << endl;
			continue;
		}
		//primes.clear();
		int *primes = primes_map[it++];
		int lower = min(k, n - k);
		int upper = max(k, n - k);

		for (int i = upper + 1; i <= n; i++) {
			if (is_prime_fast(i)) {
				primes[i]++;
			} else {
				for (int j = 2; j < i; j++) {
					if (is_prime_fast(j)) {
						int icpy = i;
						while (icpy % j == 0) {
							icpy /= j;
							primes[j]++;
						}
					}
				}
			}
		}

		for (int i = 2; i <= lower; i++) {
                       	if (is_prime_fast(i)) {
                               	primes[i]--;
                       	} else {
                               	for (int j = 2; j < i; j++) {
                                       	if (is_prime_fast(j)) {
                                               	int icpy = i;
                                               	while (icpy % j == 0) {
                                                       	icpy /= j;
                                                       	primes[j]--;
                                               	}
                                       	}	
                               	}
                       	}
                }

		long long int ret = 1;

		for (int i = 2; i <= n; i++) {
			if (is_prime_fast(i)) {
         			int cnt = primes[i];
				if (cnt > 0) {
                			ret *= (cnt + 1);
                		}
			}
        	}

		cout << ret << endl;
	}
}
