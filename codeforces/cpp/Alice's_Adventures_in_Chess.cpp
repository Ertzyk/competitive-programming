#include <iostream>
using namespace std;

string solve(int a, int b, int n, string moves){
    int posx = 0, posy = 0;
    for(int i = 0; i < 20; i++){
        for(char x: moves){
            if(x == 'N'){
                posy += 1;
            } else if (x == 'S'){
                posy -= 1;
            } else if (x == 'E'){
                posx += 1;
            } else {
                posx -= 1;
            }
            if(posx == a && posy == b){
                return "YES";
            }
        }
    }
    return "NO";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        string moves;
        cin >> n >> a >> b >> moves;
        cout << solve(a, b, n, moves) << "\n";
    }
    return 0;
}