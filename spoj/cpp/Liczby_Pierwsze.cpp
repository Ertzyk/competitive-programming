#include <iostream>
#include <bitset>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    bitset<10001> sieve;
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i < 10001; i++){
        if(sieve[i]){
            for(int j = i*i; j < 10001; j += i){
                sieve[j] = 0;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ((sieve[n]) ? "TAK\n" : "NIE\n");
    }
    return 0;
}