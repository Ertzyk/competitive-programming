#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, A, B, cost = 0;
    cin >> n >> k >> A >> B;
    while(n){
        if(n%k){
            cost += (n%k)*A;
            n -= n%k;
        } else {
            if((n - n/k)*A < B){
                cost += A*n;
                break;
            }
            cost += B;
            n /= k;
        }
    }
    cout << cost - A << '\n';
    return 0;
}