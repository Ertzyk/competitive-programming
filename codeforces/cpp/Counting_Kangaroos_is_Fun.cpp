#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> s(n);
    for(int &x: s) cin >> x;
    sort(s.rbegin(), s.rend());
    int l = 0, r = n/2, ans = 0;
    while(l <= r){
        int m = (l + r)/2;
        bool good = true;
        for(int i = 0; i < m; i++){
            if(s[i] < 2*s[n - m + i]){
                good = false;
                break;
            }
        }
        if(good){
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << n - ans << '\n';
    return 0;
}