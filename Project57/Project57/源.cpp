#define _CRT_SECURE_NO_WARNINGS 1
//约数个数
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
const int MOD = 1e9 + 7;

unordered_map<int, int> primes;
int n;

int main() {
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        for (int i = 2; i <= x / i; i++)
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }

        if (x > 1) primes[x]++;
    }

    LL res = 1;
    for (auto p : primes) res = res * (p.second + 1) % MOD;

    printf("%lld\n", res);
    return 0;
}

//约数之和
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 110;
const int MOD = 1e9 + 7;
unordered_map<int, int> primes;
int n;

int main() {
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        for (int i = 2; i <= x / i; i++)
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }
        if (x > 1) primes[x]++;
    }

    LL res = 1;
    for (auto p : primes) {
        LL a = p.first, b = p.second; //质数，几个

        LL t = 1;
        while (b--) t = (t * a + 1) % MOD;
        res = res * t % MOD;
    }
    printf("%lld\n", res);
    return 0;
}
