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
        bool flag = false;
        sort(a.begin(), a.end());
        for(int i = 1; i < n - 1; i += 2){
            if(a[i] != a[i + 1]){
                flag = true;
                break;
            }
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}