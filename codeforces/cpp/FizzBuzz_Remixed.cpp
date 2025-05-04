#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << n/15*3 + min(3, n%15 + 1) << '\n';
    }
    return 0;
}