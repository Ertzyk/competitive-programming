#include <iostream>
#include <vector>
#include <unordered_set>
#include <bitset>
using namespace std;

void solve(const vector<int>& primes){
    int n;
    cin >> n;
    unordered_set<int> visited;
    while(n--){
        int x;
        cin >> x;
        int k = x;
        for(int d: primes){
            if(d*d > x || k == 1) break;
            if(k%d == 0){
                if(visited.count(d)){
                    cout << "YES\n";
                    while(n--){
                        int black_hole;
                        cin >> black_hole;
                    }
                    return;
                }
                visited.insert(d);
                while(k%d == 0) k /= d;
            }
        }
        if(k > 1){
            if(visited.count(k)){
                cout << "YES\n";
                while(n--){
                    int black_hole;
                    cin >> black_hole;
                }
                return;
            }
            visited.insert(k);
        }
    }
    cout << "NO\n";
    return;
}

int main(){
    int t;
    cin >> t;
    vector<int> primes;
    bitset<31622> sieve;
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i < 31622; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j = i*i; j < 31622; j += i) sieve[j] = 0;
        }
    }
    while(t--) solve(primes);
    return 0;
}