#include <iostream>
#include <vector>
using namespace std;

bool is_sorted(vector<int> &v){
    for(int i = 0; i < v.size() - 1; i++) if(v[i + 1] < v[i]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x, ans = 0, p = 0;
        cin >> n >> x;
        vector<int> a(n);
        for(int &r: a) cin >> r;
        while(!is_sorted(a)){
            while(p < n && a[p] <= x) p++;
            if(p == n) break;
            swap(a[p], x);
            ans++;
        }
        if(p == n) cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}