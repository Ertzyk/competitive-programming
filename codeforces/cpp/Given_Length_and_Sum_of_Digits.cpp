#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, s;
    cin >> m >> s;
    if(s == 0 && m == 1){
        cout << "0 0";
        return 0;
    }
    if(s == 0 || 9*m < s){
        cout << "-1 -1";
        return 0;
    }
    string min_num = "1", max_num = "1";
    for(int i = 0; i < m - 1; i++){
        min_num += '0';
        max_num += '0';
    }
    int i = 0, k = 1;
    while(k < s){
        if(max_num[i] - '0' < 9) {
            max_num[i] = (char)((int)max_num[i] + 1);
            k++;
        }
        else i++;
    }
    k = 1, i = m - 1;
    while(k < s){
        if(min_num[i] - '0' < 9) {
            min_num[i] = (char)((int)min_num[i] + 1);
            k++;
        }
        else i--;
    }
    cout << min_num << ' ' << max_num;
    return 0;
}