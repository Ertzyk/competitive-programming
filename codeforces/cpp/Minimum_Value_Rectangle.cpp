#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        unordered_map<int, int> count;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            count[a]++;
        }
        bool found = false;
        vector<int> sides;
        for(auto pr: count){
            if(pr.second >= 4){
                cout << pr.first << ' ' << pr.first << ' ' << pr.first << ' ' << pr.first << '\n';
                found = true;
                break;
            } else if(pr.second >= 2) sides.push_back(pr.first);
        }
        if(!found){
            sort(sides.begin(), sides.end());
            int a = sides[0], b = sides[1];
            double k = (double)b/(double)a;
            for(int i = 2; i < sides.size(); i++){
                if((double)sides[i]/(double)sides[i - 1] < k){
                    k = (double)sides[i]/(double)sides[i - 1];
                    a = sides[i - 1];
                    b = sides[i];
                }
            }
            cout << a << ' ' << a << ' ' << b << ' ' << b << '\n';
        }
    }
    return 0;
}