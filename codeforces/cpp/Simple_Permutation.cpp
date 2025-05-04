#include <iostream>
#include <set>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    bitset<300000> sieve;
    sieve.set();
    sieve[0] = sieve[1] = false;
    for(ll i = 2; i < 300000; i++){
        if(sieve[i]){
            for(ll j = i*i; j < 300000; j += i){
                sieve[j] = false;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, s = 0, used, count = 0;
        cin >> n;
        set<int> not_used;
        for(int i = 1; i <= n; i++) not_used.insert(i);
        for(int i = 0; i < n; i++){
            bool flag = true;
            for(int x: not_used){
                if(sieve[(x + s - 1)/(i + 1) + 1]){
                    count++;
                    used = x;
                    cout << x << ' ';
                    s += x;
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << *not_used.begin() << ' ';
                not_used.erase(*not_used.begin());
            }
            else not_used.erase(used);
        }
        cout << count << '\n';
    }
    return 0;
}