#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int max_bill_small_side = 0, max_bill_large_side = 0;
    while(n--){
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(x > y) swap(x, y);
        if(c == '+'){
            max_bill_small_side = max(max_bill_small_side, x);
            max_bill_large_side = max(max_bill_large_side, y);
        } else {
            if(x >= max_bill_small_side && y >= max_bill_large_side) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}