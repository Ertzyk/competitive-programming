#include <iostream>
#include <vector>
using namespace std;

void solve(int l, int r, const vector<int>& a, vector<int>& result, int depth){
    int max_value = 0, max_index = -1;
    for(int i = l; i <= r; i++){
        if(a[i] > max_value){
            max_value = a[i];
            max_index = i;
        }
    }
    result[max_index] = depth;
    if(l <= max_index - 1) solve(l, max_index - 1, a, result, depth + 1);
    if(max_index + 1 <= r) solve(max_index + 1, r, a, result, depth + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), result(n);
        for(int &x: a) cin >> x;
        solve(0, n - 1, a, result, 0);
        for(int x: result) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}