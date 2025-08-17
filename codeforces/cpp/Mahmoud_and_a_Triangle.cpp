#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());
    for(int i = 0; i < n - 2; i++){
        if(a[i] + a[i + 1] > a[i + 2]){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}