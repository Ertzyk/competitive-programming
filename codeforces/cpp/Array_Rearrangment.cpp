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
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n);
        for(int &x: a) cin >> x;
        for(int &x: b) cin >> x;
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        bool out = false;
        for(int i = 0; i < n; i++){
            if(a[i] + b[i] > x){
                cout << "No\n";
                out = true;
                break;
            }
        }
        if(!out) cout << "Yes\n";
    }
    return 0;
}