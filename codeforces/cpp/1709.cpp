#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void bucket_sort(vector<int>& a, vector<pair<int, int>>& moves, const int type){
    for(int i = a.size() - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                moves.push_back({type, j + 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int &x: a) cin >> x;
        for(int &x: b) cin >> x;
        vector<pair<int, int>> result;
        bucket_sort(a, result, 1);
        bucket_sort(b, result, 2);
        for(int i = 0; i < n; i++) if(a[i] > b[i]) result.push_back({3, i + 1});
        cout << result.size() << '\n';
        for(auto p: result) cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}