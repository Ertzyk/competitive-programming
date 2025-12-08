#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    vector<int> primes, res;
    primes.reserve(n);
    res.reserve(n);
    for(int i = 2; i <= n; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j = i*i; j <= n; j += i){
                sieve[j] = false;
            }
        }
    }
    for(int p: primes){
        res.push_back(p);
        int k = n/p;
        while(k >= p){
            res.push_back(res.back()*p);
            k /= p;
        }
    }
    cout << res.size() << '\n';
    for(int x: res) cout << x << ' ';
    cout << '\n';
    return 0;
}