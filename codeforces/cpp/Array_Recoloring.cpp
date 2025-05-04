#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        if(k == 1){
            if(a[0] > a[n - 1]){
                cout << a[0] + *max_element(a.begin() + 1, a.end()) << '\n';
            } else {
                cout << a[n - 1] + *max_element(a.begin(), a.end() - 1) << '\n';
            }
        } else {
            sort(a.rbegin(), a.rend());
            cout << accumulate(a.begin(), a.begin() + k + 1, (ll)0) << '\n';
        }
    }
    return 0;
}