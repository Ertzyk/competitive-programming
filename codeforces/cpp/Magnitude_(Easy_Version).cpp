#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        ll prev_max = abs(a[0]), suma = a[0];
        for(int i = 1; i < n; i++){
            suma += a[i];
            if(a[i] >= 0) prev_max += a[i];
            else prev_max = max(prev_max + a[i], abs(suma));
        }
        cout << prev_max << '\n';
    }
    return 0;
}