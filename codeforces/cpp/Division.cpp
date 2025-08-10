#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> sieve(31623, true);
    vector<ll> primes;
    sieve[0] = sieve[1] = false;
    for(ll i = 2; i < 31623; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(ll j = i*i; j < 31623; j += i) sieve[j] = false;
        }
    }
    int t;
    cin >> t;
    while(t--){
        ll p, q;
        cin >> p >> q;
        if(p%q) cout << p << '\n';
        else{
            ll ans = 0, k = 0;
            unordered_map<ll, ll> q_fact;
            while(q > 1 && k < primes.size()){
                while(q%primes[k] == 0){
                    q /= primes[k];
                    q_fact[primes[k]]++;
                }
                k++;
            }
            if(q > 1) q_fact[q]++;
            for(auto pairs: q_fact){
                ll temp = p;
                while(temp%pairs.first == 0) temp /= pairs.first;
                for(int i = 0; i < pairs.second - 1; i++) temp *= pairs.first;
                ans = max(ans, temp);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}