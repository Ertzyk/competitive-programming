#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 1;
    cin >> n;
    vector<bool> sieve(317, true);
    vector<int> primes;
    sieve[0] = sieve[1] = false;
    for(int i = 2; i < 317; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j = i*i; j < 317; j += i) sieve[j] = false;
        }
    }
    unordered_map<int, int> count_primes;
    for(int i = 0; i < n; i++){
        int s, p = 0;
        cin >> s;
        while(s > 1 && p < primes.size()){
            if(s%primes[p] == 0){
                count_primes[primes[p]]++;
                while(s%primes[p] == 0) s /= primes[p];
            }
            p++;
        }
        if(s > 1) count_primes[s]++;
    }
    for(auto p: count_primes) result = max(result, p.second);
    cout << result << '\n';
    return 0;
}