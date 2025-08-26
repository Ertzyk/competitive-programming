#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, p = 0;
    cin >> n >> k;
    vector<bool> sieve(317, true);
    vector<int> primes, fact;
    sieve[0] = sieve[1] = false;
    for(int i = 2; i < 317; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j = i*i; j < 317; j += i) sieve[j] = false;
        }
    }
    while(n > 1 && p < (int)primes.size()){
        while(n%primes[p] == 0){
            n /= primes[p];
            fact.push_back(primes[p]);
        }
        p++;
    }
    if(n > 1) fact.push_back(n);
    if((int)fact.size() < k){
        cout << "-1\n";
        return 0;
    }
    int prod = 1;
    while((int)fact.size() >= k){
        prod *= fact.back();
        fact.pop_back();
    }
    fact.push_back(prod);
    for(int x : fact) cout << x << ' ';
    cout << '\n';
    return 0;
}