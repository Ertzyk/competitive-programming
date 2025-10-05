#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 100;

void solve(int k){
    vector<vector<bool>> result(SIZE, vector<bool>(SIZE, false));
    for(int i = 1; i < SIZE; i++){
        result[0][i] = true;
        result[i][0] = true;
    }
    for(int i = 1; i < SIZE; i++){
        for(int j = i + 1; j < SIZE; j++){
            result[i][j] = true;
            result[j][i] = true;
            k--;
            if(k == 0){
                for(int k = 0; k < SIZE; k++){
                    for(int l = 0; l < SIZE; l++) cout << ((result[k][l]) ? '1' : '0');
                    cout << '\n';
                }
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    // cout << SIZE << '\n';
    // solve(k);
    for(int i = 3; i <= 100; i++){
        cout << i << ": " << i*(i - 1)*(i - 2)/6 << ' ' << i*(i - 1)*(i - 2)/6 - (i - 2)*(i/2) << '\n';
    }
    return 0;
}