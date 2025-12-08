#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, max_idx = 0, min_idx = 0;
        string s;
        cin >> n >> s;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(i == 0 && s[i] == '1') flag = true;
            if(i == n - 1 && s[i] == '1') flag = true;
            if(a[i] == 1 && s[i] == '1') flag = true;
            if((a[i] == n) && s[i] == '1') flag = true;
            if(a[i] == n) max_idx = i + 1;
            if(a[i] == 1) min_idx = i + 1;
            if(flag) break;
        }
        if(flag) cout << "-1\n";
        else {
            cout << "5\n";
            cout << min(min_idx, max_idx) << ' ' << max(min_idx, max_idx) << '\n';
            cout << 1 << ' ' << min_idx << '\n';
            cout << min_idx << ' ' << n << '\n';
            cout << 1 << ' ' << max_idx << '\n';
            cout << max_idx << ' ' << n << '\n';
        }
    }
    return 0;
}