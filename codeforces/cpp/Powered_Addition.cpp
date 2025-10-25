#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, result = 0;
        cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        for(int i = 0; i < n - 1; i++){
            int diff = a[i] - a[i + 1], cnt = 0;
            while(diff > 0){
                diff >>= 1;
                cnt++;
            }
            result = max(result, cnt);
            a[i + 1] = max(a[i + 1], a[i]);
        }
        cout << result << '\n';
    }
    return 0;
}