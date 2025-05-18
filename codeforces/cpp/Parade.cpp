#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int beauty = 0, max_l = 0, max_r = 0, max_l_column = 0, max_r_column = 0;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        beauty += l - r;
        if(2*l - 2*r > max_l){
            max_l = 2*l - 2*r;
            max_l_column = i;
        }
        if(2*r - 2*l > max_r){
            max_r = 2*r - 2*l;
            max_r_column = i;
        }
    }
    int result_col = 0, beauty_start = beauty;
    beauty = abs(beauty);
    if(max_l_column > 0 && abs(beauty_start - max_l) > beauty){
        result_col = max_l_column;
        beauty = abs(beauty_start - max_l);
    }
    if(max_r_column > 0 && beauty_start + max_r > beauty) result_col = max_r_column;
    cout << result_col << '\n';
    return 0;
}