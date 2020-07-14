/*
 * We receive as input a ciphertest b of length m and the last n characters of the plaintext a.
 * The key has an initialization vector of length n, after which k[n + i] = a[i].
 * 
 * The encryption function is: b[i] = (a[i] + k[i]) (mod 26)
 *
 * Clearly, we have: k[i] = b[i] - a[i] (mod 26)
 * 		and: a[i] = k[i + n]
 *
 * Hence: a[i] = (b[i + n] - a[i + n]) (mod 26) 
 */

#include <bits/stdc++.h>
using namespace std;

int mod (int a, int b) {
	return ((a % b) + b) % b;
}

int main() {
	int n, m;
	string last, cipher;
	while(cin >> n >> m >> last >> cipher) {	
		string plain = cipher;
		for (int i = 0; i < n; i++) {
			plain[m - n + i] = last[i];
		}
	
		for (int i = m - n - 1; i >= 0; i--) {
			plain[i] = mod((int)(cipher[i + n] - 'a') - (int)(plain[i + n] - 'a'), 26) + 'a'; 
		}
		
		cout << plain << endl;
	}
}
