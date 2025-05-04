#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, b, c;
        cin >> n >> b >> c;
        if(b > 0){
            ll z = (n > c) ? ((n - c)%b) ? (n - c)/b + 1 : (n - c)/b : 0;
            cout << n - z << "\n";
        } else {
            if (n > c + 2){
                cout << -1 << "\n";
            } else if (n <= c){
                cout << n << "\n";
            } else {
                cout << n - 1 << "\n";
            }
        }
    }
}