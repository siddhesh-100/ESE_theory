#include <iostream>
using namespace std;
void bubbleSort(int a[], int n){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}
void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    printArray(a, n);
    bubbleSort(a, n);
    printArray(a, n);
    return 0;
}