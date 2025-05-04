#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> primes;
    bitset<3162> sieve;
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i < 3162; i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j = i*i; j < 3162; j += i) sieve[j] = 0;
        }
    }
    while(n--){
        int x, y, res = INT_MAX;
        cin >> x >> y;
        int d = y - x;
        for(int k: primes){
            if(d == 1 || k*k > y - x) break;
            if(d%k == 0) res = min(k - (x - 1)%k - 1, res);
            while(d%k == 0) d /= k;
        }
        if(d > 1) res = min(d - (x - 1)%d - 1, res);
        cout << ((res == INT_MAX) ? -1 : res) << '\n';
    }
    return 0;
}