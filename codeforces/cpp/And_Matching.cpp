#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k < n - 1){
            cout << k << ' ' << n - 1 << '\n';
            for(int i = 1; i < n/2; i++){
                if(i == k) cout << "0 " << (i^(n - 1)) << '\n';
                else if(i == (k^(n - 1))) cout << "0 " << i << '\n';
                else cout << i << ' ' << (i^(n - 1)) << '\n';
            }
        } else {
            if(n == 4){
                cout << "-1\n";
                continue;
            }
            cout << "1 3\n" << n - 2 << ' ' << n - 1 << "\n0 " << n - 4 << "\n2 " << n - 3 << '\n';
            for(int i = 4; i < n/2; i++) cout << i << ' ' << (i^(n - 1)) << '\n';
        }
    }
    return 0;
}