#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, count_conseq = 0;
        cin >> n;
        vector<int> a(n);
        bool good = true;
        for(int i = 1; i <= n; i++){
            int a;
            cin >> a;
            if(i != a && good){
                count_conseq++;
                good = false;
            } else if(i == a) good = true;
        }
        if(count_conseq <= 1) cout << count_conseq << '\n';
        else cout << "2\n";
    }
    return 0;
}