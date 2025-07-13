#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int vector_gcd(const vector<int> &v){
    if(v.size() == 1) return v[0];
    int g = gcd(v[0], v[1]);
    for(int i = 2; i < v.size(); i++) g = gcd(g, v[i]);
    return g;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, count_max = -1;
    cin >> n;
    vector<int> a(n), primes;
    for(int &x: a) cin >> x;
    int g = vector_gcd(a);
    if(g > 1) for(int i = 0; i < n; i++) a[i] /= g;
    vector<bool> sieve(3872, true);
    sieve[0] = sieve[1] = false;
    for(int i = 2; i < 3872; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j = i*i; j < 3872; j += i) sieve[j] = false;
        }
    }
    unordered_map<int, int> count_primes;
    for(int i = 0; i < n; i++){
        int d = 0;
        while(a[i] > 1 && d < primes.size()){
            if(a[i]%primes[d] == 0){
                count_primes[primes[d]]++;
                while(a[i]%primes[d] == 0) a[i] /= primes[d];
            }
            d++;
        }
        if(a[i] > 1) count_primes[a[i]]++;
    }
    for(auto p: count_primes) count_max = max(count_max, p.second);
    cout << (count_max != -1 ? n - count_max : -1) << '\n';
    return 0;
}