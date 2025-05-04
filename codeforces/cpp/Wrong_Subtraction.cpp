#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        if(n%10) n--;
        else n /= 10;
    }
    cout << n;
    return 0;
}