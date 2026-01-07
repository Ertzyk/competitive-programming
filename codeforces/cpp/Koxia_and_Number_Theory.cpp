#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
using ll = long long;

void solve(const vector<ll> &primes){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    sort(a.begin(), a.end());
    map<ll, set<ll>> mp;
    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            ll g = a[j] - a[i];
            if(g == 0){
                cout << "NO\n";
                return;
            }
            for(ll pr: primes){
                if(g%pr == 0){
                    mp[pr].insert(a[i]%pr);
                    do {
                        g /= pr;
                    } while(g%pr == 0);
                }
                if(g == 1) break;
            }
        }
    }
    for(auto pr: mp){
        if(pr.second.size() == pr.first){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    vector<ll> sieve(5000, true), primes;
    primes.reserve(2500);
    sieve[0] = sieve[1] = false;
    for(ll i = 2; i < 5000; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(ll j = i*i; j < 5000; j += i){
                sieve[j] = false;
            }
        }
    }
    while(t--){
        solve(primes);
    }
    return 0;
}