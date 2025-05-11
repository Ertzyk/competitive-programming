#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0, cur = 0;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        cur += b - a;
        result = max(result, cur);
    }
    cout << result << '\n';
    return 0;
}