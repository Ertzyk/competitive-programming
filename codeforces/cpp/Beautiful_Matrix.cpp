#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j ++){
            int x;
            cin >> x;
            if(x == 1){
                a = i; b = j;
            }
        }
    }
    cout << abs(a - 2) + abs(b - 2);
    return 0;
}