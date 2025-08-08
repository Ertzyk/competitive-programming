#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, first_TV = 0, second_TV = 0;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto &p: a) cin >> p.first >> p.second;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(first_TV <= a[i].first) first_TV = a[i].second + 1;
        else if(second_TV <= a[i].first) second_TV = a[i].second + 1;
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}