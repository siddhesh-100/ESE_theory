#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &v){
    int n = v.size();
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; i < i; j++){
            if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
}
void print(vector<int> &v){
    for(const auto &i : v) cout << i << " ";
    cout << endl;
}
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    print(v);
    bubbleSort(v);
    print(v);
    return 0;
}