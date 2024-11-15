#include <iostream>
using namespace std;
void insertionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && a[j] < a[j - 1]){
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}
void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    print(a, n);
    insertionSort(a, n);
    print(a, n);
    return 0;
}