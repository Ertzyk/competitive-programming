#include <iostream>
#include <bitset>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, b;
    cin >> n >> b;
    bitset<1000001> sieve;
    vector<ll> primes;
    sieve.set();
    sieve[0] = sieve[1] = 1;
    for(ll i = 2; i < 1000001; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(ll j = i*i; j < 1000001; j += i) sieve[j] = 0;
        }
    }
    vector<pair<ll, ll>> divisors;
    int i = 0;
    while(i < primes.size() && primes[i]*primes[i] <= b && b > 1){
        if(b%primes[i] == 0){
            ll count = 0;
            while(b%primes[i] == 0){
                count++;
                b /= primes[i];
            }
            divisors.push_back({primes[i], count});
        }
        i++;
    }
    if(b > 1) divisors.push_back({b, 1});
    ll result = LLONG_MAX;
    for(auto p: divisors){
        ll k = p.first, vp = 0;
        while(k <= n){
            vp += n/k;
            if (k > LLONG_MAX/p.first) break;
            k *= p.first;
        }
        result = min(result, vp/p.second);
    }
    cout << result;
    return 0;
}