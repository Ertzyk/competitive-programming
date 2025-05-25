#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    bool easy = true;
    while(n--){
        int x;
        cin >> x;
        if(x == 1) easy = false;
    }
    cout << ((easy) ? "EASY\n" : "HARD\n");
    return 0;
}