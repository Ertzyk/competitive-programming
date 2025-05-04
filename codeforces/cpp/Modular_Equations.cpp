#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, result = 0;
    cin >> a >> b;
    if(a == b){
        cout << "infinity";
        return 0;
    }
    for(int i = 1; i*i <= a - b; i++){
        if((a - b)%i == 0){
            if(i > b){
                result++;
            }
            if((a - b)/i > b && i != (a - b)/i){
                result++;
            }
        }
    }
    cout << result;
    return 0;
}