#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0;
    cin >> n;
    while(n--){
        int p, q;
        cin >> p >> q;
        if(q - p >= 2) result++;
    }
    cout << result << '\n';
    return 0;
}