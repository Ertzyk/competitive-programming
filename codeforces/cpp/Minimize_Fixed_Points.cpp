#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
        for(ll i = 2; i <= n; i++) if(sieve[i]) for(ll j = i*i; j <= n; j += i) sieve[j] = false;
        vector<int> result(n + 1, 0);
        result[1] = 1;
        for(int i = n; i > 1; i--){
            if(sieve[i]){
                if(2*i > n) result[i] = i;
                else {
                    int prev = i;
                    for(int j = 2*i; j <= n; j += i) if(result[j] == 0){
                        result[j] = prev;
                        prev = j;
                    }
                    result[i] = prev;
                }
            }
        }
        for(int i = 1; i <= n; i++) cout << result[i] << " \n"[i == n];
    }
    return 0;
}