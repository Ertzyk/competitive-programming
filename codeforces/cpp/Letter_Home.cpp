#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        cout << a[n - 1] - a[0] + min(abs(s - a[0]), abs(a[n - 1] - s)) << '\n';
    }
    return 0;
}