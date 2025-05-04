#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int block_2 = n*2, block_3 = 3*m, repeat = min(n/3, m/2);
    while(repeat > 0){
        if(block_2 > block_3){
            block_3 += 3;
            if(block_3%2 == 0 && block_3 <= block_2){
                repeat++;
            }
        } else {
            block_2 += 2;
            if(block_2%3 == 0 && block_2 <= block_3){
                repeat++;
            }
        }
        repeat--;
    }
    cout << max(block_2, block_3);
    return 0;
}