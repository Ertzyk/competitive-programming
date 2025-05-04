#include <iostream>
using namespace std;

bool is_prime(const int x){
    for(int d = 2; d*d <= x; d++){
        if(x%d == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(is_prime(n)){
        cout << 1;
    } else if(n%2 == 0 || is_prime(n - 2)){
        cout << 2;
    } else {
        cout << 3;
    }
    return 0;
}