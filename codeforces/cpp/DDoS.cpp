#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cur = 0, x, result = 0;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> x;
        cur += x;
        a[i] = cur;
    }
    for(int l = 1; l <= n; l++){
        for(int r = l; r <= n; r++){
            if(r - l + 1 <= result) continue;
            if(a[r] - a[l - 1] > 100*(r - l + 1)) result = r - l + 1;
        }
    }
    cout << result << '\n';
    return 0;
}