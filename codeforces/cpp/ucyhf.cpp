#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
using ll = long long;

int reverse_num(int x){
    int result = 0;
    while(x){
        result *= 10;
        result += x%10;
        x /= 10;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d, k = 0;
    cin >> d;
    bitset<1000000> sieve;
    sieve.set();    
    sieve[0] = sieve[1] = 0;
    for(ll i = 2; i < 1000000; i++){
        if(sieve[i]){
            for(ll j = i*i; j < 1000000; j += i) sieve[j] = 0;
        }
    }
    for(int i = 13; i < 1000000; i++){
        if(sieve[i]){
            int j = reverse_num(i);
            if(i != j && sieve[j]) k++;
            if(k == d){
                cout << i;
                break;
            }
        }
    }
    return 0;
}