#include <iostream>
#include <vector>
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
        for(int &x : a) cin >> x;
        vector<bool> result (n, false);
        int cur_min = 1000001;
        for(int i = 0; i < n ; i++) if(cur_min > a[i]){
                cur_min = a[i];
                result[i] = true;
        }
        int cur_max = 0;
        for(int i = n - 1; i >= 0; i--) if(cur_max < a[i]){
                result[i] = true;
                cur_max = a[i];
        }
        for(bool x: result) cout << ((x) ? '1' : '0');
        cout << '\n';
    }
    return 0;
}