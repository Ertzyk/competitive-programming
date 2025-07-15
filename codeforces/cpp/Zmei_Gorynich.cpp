#include <iostream>
#include <climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x, max_hit = 0, max_diff = INT_MIN;
        cin >> n >> x;
        while(n--){
            int d, h;
            cin >> d >> h;
            max_hit = max(max_hit, d);
            max_diff = max(max_diff, d - h);
        }
        x -= max_hit;
        if(x <= 0){
            cout << "1\n";
            continue;
        }
        if(max_diff <= 0){
            cout << "-1\n";
            continue;
        }
        cout << (x - 1)/max_diff + 2 << '\n';
    }
    return 0;
}