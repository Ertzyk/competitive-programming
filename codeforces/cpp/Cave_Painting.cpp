#include <iostream>
#include <unordered_set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

ll prime_degree(ll a, ll p){
    ll result = -1;
    while(a > 0) {
        a /= p;
        result++;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, p = 1;
    cin >> n >> k;
    if(k >= 43){
        cout << "No";
        return 0;
    }
    unordered_set<ll> primes;
    bitset<43> sieve;
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i <= k; i++){
        if(sieve[i]){
            primes.insert(i);
            for(int j = i*i; j <= k; j += i){
                sieve[j] = 0;
            }
        }
    }
    for(ll x: primes){
        p *= pow(x, prime_degree(k, x));
    }
    cout << ((n%p == p - 1) ? "Yes" : "No");
    return 0;
}