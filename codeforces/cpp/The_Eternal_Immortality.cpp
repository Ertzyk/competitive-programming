#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    if(b - a >= 5) cout << "0\n";
    else{
        ll m = 1;
        for(ll i = a + 1; i <= b; i++){
            m *= i%10;
            m %= 10;
        }
        cout << m << '\n';
    }
    return 0;
}