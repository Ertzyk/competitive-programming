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
        int n, last = 0;
        cin >> n;
        vector<int> res;
        for(int i = 1; i*i <= n; i++){
            if(res.empty() || res.back() != n/i) res.push_back(n/i);
            last = i;
        }
        for(int i = last; i >= 0; i--) if(res.empty() || res.back() != i) res.push_back(i);
        reverse(res.begin(), res.end());
        cout << res.size() << '\n';
        for(int x: res) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}