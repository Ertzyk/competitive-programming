#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, res = 1;
        cin >> n;
        while(n > 0){
            int a = n%10;
            res *= (a + 1)*(a + 2)/2;
            n /= 10;
        }
        cout << res << '\n';
    }
    return 0;
}