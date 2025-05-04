#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
        vector<int> changes(n);
        int cur = 0;
        for(int i = 0; i < n - 1; i++){
            changes[i] = cur;
            if(a[i] != a[i + 1]) cur++;
        }
        changes[n - 1] = cur;
        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            if(changes[l - 1] == changes[r - 1]){
                cout << "-1 -1\n";
                continue;
            }
            auto it = upper_bound(changes.begin(), changes.end(), changes[l - 1]);
            cout << it - changes.begin() << ' ' << it - changes.begin() + 1 << '\n';
        }
    }
    return 0;
}