#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, result = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    for(int i = 1; i < n; i++) if(a[i] + a[i - 1] < k){
        result += k - a[i - 1] - a[i];
        a[i] = k - a[i - 1];
    }
    cout << result << '\n';
    for(int x: a) cout << x << ' '; 
    return 0;
}