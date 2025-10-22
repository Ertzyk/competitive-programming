#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        if(a[0] + a[1] <= a[n - 1]) cout << "1 2 " << n << '\n';
        else cout << "-1\n";
    }
    return 0;
}