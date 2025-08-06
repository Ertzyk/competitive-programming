#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<bool> sieve(31622, true);
    vector<int> primes;
    sieve[0] = sieve[1] = false;
    for(int i = 2; i < 31622; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j = i*i; j < 31622; j += i) sieve[j] = false;
        }
    }
    while(t--){
        int n;
        cin >> n;
        bool found = false;
        for(int p: primes){
            if(n%p == 0){
                cout << n/p << ' ' << n - n/p << '\n';
                found = true;
                break;
            }
        }
        if(!found) cout << "1 " << n - 1 << '\n';
    }
    return 0;
}