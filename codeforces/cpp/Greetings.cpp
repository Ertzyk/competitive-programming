#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, result = 0;
        cin >> n;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
        sort(a.begin(), a.end());
        set<int> seen;
        for(int i = 0; i < n; i++){
            result += distance(seen.upper_bound(a[i].second), seen.end());
            seen.insert(a[i].second);
        }
        cout << result << '\n';
    }
    return 0;
}