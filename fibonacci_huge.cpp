#include <iostream>
#include<map>
using namespace std;
#define long long long
long mod;
long get_fibonacci_huge_naive(long  n, long  m) {
    if (n <= 1)
        return n;

    long previous = 0;
    long current  = 1;
    for (long i = 0; i < n - 1; ++i) {
        long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
long M = 1000000007; // modulo
map<long, long> F;

long f(long n) {
	if (F.count(n)) return F[n];
	long k = n / 2;
	if (n % 2 == 0) { // n=2*k
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
	}
}
int main() {
    long n, m;
    std::cin >> n >> m;
    F[0] = F[1] = 1;
    M = m;
    std::cout << (n==0 ? 0 : f(n-1)) % m << endl;
}
