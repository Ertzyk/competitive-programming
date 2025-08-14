#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Coord{
    int a, b, c;
    float value(){
        return ((float)a + (float)b)/(float)c;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    unordered_map<float, int> count;
    vector<Coord> v(m);
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        vector<int> nums;
        nums.reserve(3);
        int p = 0;
        while(p < s.size()){
            while(s[p] < '0' || s[p] > '9') p++;
            int x = 0;
            while(p < s.size() && s[p] >= '0' && s[p] <= '9'){
                x *= 10;
                x += s[p] - '0';
                p++;
            }
            nums.push_back(x);
        }
        v[i].a = nums[0];
        v[i].b = nums[1];
        v[i].c = nums[2];
        count[v[i].value()]++;
    }
    for(int i = 0; i < m; i++) cout << count[v[i].value()] << " \n"[i == m - 1];
    return 0;
}