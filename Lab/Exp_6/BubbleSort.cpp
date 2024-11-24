#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &v){
    for(int i = v.size() - 1; i > -1; i--){
        for(int j = 0; j < i; j++){
            if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
}
void print(vector<int> &v){
    for(const auto &i : v) cout << i << " ";
    cout << "\n";
}
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    cout << "Before Sorting: ";
    print(v);
    cout << "After Sorting: ";
    bubbleSort(v);
    print(v);
    return 0;
}