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
        if((n&(n - 1)) == 0 && n%2 == 0){
            int k = 0;
            while(n%2 == 0){
                n /= 2;
                k++;
            }
            n = k;
        } 
        cout << ((n%2) ? "Bob\n" : "Alice\n");
    }
    return 0;
}