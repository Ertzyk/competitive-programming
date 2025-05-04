#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, result = 0;
    cin >> a >> b;
    while(a <= b){
        a *= 3;
        b *= 2;
        result++;
    }
    cout << result;
    return 0;
}