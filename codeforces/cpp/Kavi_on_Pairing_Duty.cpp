#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
const int MOD = 998244353;

int count_divisors(int x, const vector<int>& primes){
    int p = 0, result = 1;
    while(p < primes.size() && x > 1){
        if(x%primes[p] == 0){
            int count = 0;
            while(x%primes[p] == 0){
                x /= primes[p];
                count++;
            }
            result *= count + 1;
        }
        p++;
    }
    if(x > 1) result *= 2;
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    bitset<1000> sieve;
    vector<int> primes;
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i < 1000; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j = i*i; j < 1000; j += i) sieve[j] = 0;
        }
    }
    int n, s = 1;
    cin >> n;
    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        dp[i] += s + count_divisors(i, primes) - 1;
        dp[i] %= MOD;
        s += dp[i];
        s %= MOD;
    }
    cout << dp[n];
    return 0;
}