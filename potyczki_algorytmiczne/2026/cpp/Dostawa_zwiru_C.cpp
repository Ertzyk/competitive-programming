#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, original_sum = 0;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        original_sum += a[i];
    }
    for(int i = 1; i < n; i++) a[i] = max(a[i], a[i - 1] - k);
    for(int i = n - 2; i >= 0; i--) a[i] = max(a[i], a[i + 1] - k);
    ll final_sum = 0;
    for(int i = 0; i < n; i++) final_sum += a[i];
    cout << final_sum - original_sum << "\n";
    return 0;
}