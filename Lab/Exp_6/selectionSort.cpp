#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        int minId = i;
        for(int j = i; j < v.size(); j++){
            if(v[minId] > v[j]) minId = j;
        }
        swap(v[minId], v[i]);
    }
}
void print(vector<int> &v){
    for(auto const &i : v) cout << i << " ";
    cout << "\n";
}
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    cout << "Before sort: ";
    print(v);
    cout << "After sort: ";
    selectionSort(v);
    print(v);
    return 0;
}