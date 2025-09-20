#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        if(k%3 == 0){
            n %= k + 1;
            cout << ((n%3 == 0 && n != k) ? "Bob\n" : "Alice\n");
        } else cout << ((n%3) ? "Alice\n" : "Bob\n");
    }
    return 0;
}