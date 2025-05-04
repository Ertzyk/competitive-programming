#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int l = 0, r = n - 1;
    while(a[l] == 0) l++;
    while(a[r] == 0) r--;
    if(l == r){
        if(a[l] == 1) cout << "TAK\n";
        else cout << "NIE\n";
        return;
    }
    if(r - l == 1){
        if(abs(a[l] - a[r]) <= 1) cout << "TAK\n";
        else cout << "NIE\n";
        return;
    }
    if(a[r - 1] < a[r]){
        cout << "NIE\n";
        return;
    }
    while(r - l > 1){
        if(a[l + 1] == 0){
            cout << "NIE\n";
            return;
        }
        a[l + 1] -= a[l];
        if(a[l + 1] < 0){
            cout << "NIE\n";
            return;
        }
        l++;
    }
    if(abs(a[l] - a[r]) <= 1) cout << "TAK\n";
    else cout << "NIE\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}