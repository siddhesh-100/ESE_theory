#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
int partition(vi &v, int low, int high){
    int piv = v[low];
    int i = low, j = high;
    while(i < j){
        while(v[i] <= piv && i < high) i++;
        while(v[j] > piv && j > low) j--;
        if(i < j) swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}
void qs(vi &v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);
        qs(v, low, pi - 1);
        qs(v, pi + 1, high);
    }
}
void printArray(vi &v){
    for(const auto &i : v)  cout << i << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vi v(n);
    for(auto &i : v) cin >> i;
    printArray(v);
    qs(v, 0, n - 1);
    printArray(v);
    return 0;
}