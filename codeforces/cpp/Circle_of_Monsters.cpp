#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        ll n, result = 0;
        cin >> n;
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; i++){
            ll x, y;
            cin >> x >> y;
            a[i] = x;
            b[i] = y;
        }
        for(int i = 1; i < n; i++){
            if(a[i] > b[i - 1]){
                result += a[i] - b[i - 1];
                a[i] = b[i - 1];
            }
        }
        if(a[0] > b[n - 1]){
            result += a[0] - b[n - 1];
            a[0] = b[n - 1];
        }
        cout << result + *min_element(a.begin(), a.end()) << '\n';
    }
    return 0;
}