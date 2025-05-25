#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, cur_min, cur_max, start;
        char response;
        cin >> n;
        if(n%2){
            cur_min = 1;
            cur_max = 1;
            start = 2;
        } else {
            cout << "? 1 2\n";
            cout.flush();
            cin >> response;
            if(response == '<'){
                cur_min = 1;
                cur_max = 2;
            } else {
                cur_min = 2;
                cur_max = 1;
            }
            start = 3;
        }
        for(int i = start; i < n; i += 2){
            cout << "? " << i << ' ' << i + 1 << '\n';
            cout.flush();
            cin >> response;
            if(response == '<'){
                cout << "? " << cur_min << ' ' << i << '\n';
                cout.flush();
                cin >> response;
                if(response == '>') cur_min = i;
                cout << "? " << cur_max << ' ' << i + 1 << '\n';
                cout.flush();
                cin >> response;
                if(response == '<') cur_max = i + 1;
            } else {
                cout << "? " << cur_min << ' ' << i + 1 << '\n';
                cout.flush();
                cin >> response;
                if(response == '>') cur_min = i + 1;
                cout << "? " << cur_max << ' ' << i << '\n';
                cout.flush();
                cin >> response;
                if(response == '<') cur_max = i;
            }
        }
        cout << "! " << cur_min << ' ' << cur_max << '\n';
        cout.flush();
    }
    return 0;
}