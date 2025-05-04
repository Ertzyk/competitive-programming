#include <iostream>
using namespace std;

int largest_digit(int n){
    int x = 0;
    while(n > 0){
        x = max(x, n%10);
        n /= 10;
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0;
    cin >> n;
    while(n){
        n -= largest_digit(n);
        result++;
    }
    cout << result;
    return 0;
}