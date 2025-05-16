#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    for(int i = 0; i < n - 1; i++){
        if(a[i] < 0){
            cout << "NO\n";
            return 0;
        }
        if(a[i]%2) a[i + 1]--;
    }
    if(a[n - 1] < 0 || a[n - 1]%2) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}