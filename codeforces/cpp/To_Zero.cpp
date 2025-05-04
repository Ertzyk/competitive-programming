#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k, result = 0;
        cin >> n >> k;
        if(n%2 == 1) {
            n -= k;
            result++;
        }
        if(n%(k - 1) == 0) result += n/(k - 1);
        else result += n/(k - 1) + 1;
        cout << result << '\n';
    }
    return 0;
}