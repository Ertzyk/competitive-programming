#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<bool> sieve((ll)sqrt(n) + 1, true);
    vector<ll> primes;
    sieve[0] = sieve[1] = false;
    for(ll i = 2; i < sieve.size(); i++){
        if(sieve[i]){
            primes.push_back(i);
            for(ll j = i*i; j < sieve.size(); j += i) sieve[j] = false;
        }
    }
    bool found = false;
    for(ll d: primes){
        if(n%d == 0){
            while(n%d == 0) n /= d;
            if(n > 1) cout << "1\n";
            else cout << d << '\n';
            found = true;
            break;
        }
    }
    if(!found) cout << n << '\n';
    return 0;
}