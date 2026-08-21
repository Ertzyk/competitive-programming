#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int A, B;
    cin >> s >> A >> B;
    if(s == "Algosia"){
        if(abs(A - B) == 1 || abs(A - B) == 999){
            cout << A + 2 << ' ' << B + 2 << '\n';
        } else {
            cout << A + 1 << ' ' << B + 1 << '\n';
        }
    } else {
        if(abs(A - B) == 1 || abs(A - B) == 999){
            cout << A - 2 << ' ' << B - 2 << '\n';
        } else {
            cout << A - 1 << ' ' << B - 1 << '\n';
        }
    }
    cout.flush();
    return 0;
}