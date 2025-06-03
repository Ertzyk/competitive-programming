#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string result;
    for(int i = 0; i < n - 1; i++){
        if(i%2) result += "I love that ";
        else result += "I hate that ";
    }
    if(n%2) result += "I hate it";
    else result += "I love it";
    cout << result << '\n';
    return 0;
}