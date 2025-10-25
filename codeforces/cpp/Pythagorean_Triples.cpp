#include <iostream>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ((int)sqrt((double)(2*n - 1)) - 1)/2 << '\n';
    }
    return 0;
}