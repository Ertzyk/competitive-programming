#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, counter = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        int x;
        cin >> s >> x;
        if(s == "TAK" && counter < 20 && (counter < 10 || x < 2)){
            cout << i << ' ';
            counter++;
        }
    }
    return 0;
}