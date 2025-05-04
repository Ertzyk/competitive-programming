#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, cur = 0;
        cin >> n;
        vector<int> a1(n), a2(n), acc1(n), acc2(n);
        for(int &x: a1) cin >> x;
        for(int &x: a2) cin >> x;
        for(int i = n - 1; i >= 0; i--){
            acc1[i] = cur;
            cur += a1[i];
        }
        cur = 0;
        for(int i = 0; i < n; i++){
            acc2[i] = cur;
            cur += a2[i];
        }
        int result = INT_MAX;
        for(int i = 0; i < n; i++) result = min(result, max(acc1[i], acc2[i]));
        cout << result << '\n';
    }
    return 0;
}