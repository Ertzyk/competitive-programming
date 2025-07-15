#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, last, before_last;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    vector<int> result(n);
    result[0] = 1;
    if(a[a[1].first].first == a[1].second || a[a[1].first].second == a[1].second){
        before_last = result[1] = a[1].first;
        last = result[2] = a[1].second;
    } else {
        before_last = result[1] = a[1].second;
        last = result[2] = a[1].first;
    }
    for(int i = 3; i < n; i++){
        result[i] = (a[before_last].first == last ? a[before_last].second : a[before_last].first);
        before_last = last;
        last = result[i];
    }
    for(int x: result) cout << x << ' ';
    cout << '\n';
    return 0;
}