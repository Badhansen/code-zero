#include<bits/stdc++.h>
using namespace std;
using LL = long long int;
LL max_pairwise_product(vector<int> &numbers){
    LL max_product = 0;
    int n = numbers.size();
    if(n == 1) return numbers[0];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            max_product = max(1ll * numbers[i] * numbers[j], max_product);
        }
    }
    return max_product;
}
LL max_pairwise_product_fast(vector<int> & numbers){
    int n = numbers.size();
    if(n == 1) return numbers[0];
    int first = max(numbers[0], numbers[1]);
    int second = min(numbers[0], numbers[1]);
    for(int i = 2; i < n; i++){
        if(numbers[i] > first){
            second = first;
            first = numbers[i];
        }
        else if(numbers[i] > second){
            second = numbers[i];
        }
    }
    return 1ll * first * second;
}
int main(){
    /*
    srand(time(NULL));
    while(1){
        int n = rand() % 1000;
        if(n == 0) continue;
        vector<int> numbers(n);
        for(int i = 0; i < n; i++){
            numbers[i] = rand() % 1000000007;
        }
        int r = max_pairwise_product(numbers);
        int q = max_pairwise_product_fast(numbers);
        if(r != q){
            cout << "WORNG " << r << " " << q << endl;
            for(auto& pairwise : numbers){
                cout << pairwise << " ";
            }
            cout << endl;
        }
        else{
            cout << "OK" << endl;
            for(auto& pairwise : numbers){
                cout << pairwise << " ";
            }
            cout << endl;
        }

    }
    */
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    cout << max_pairwise_product_fast(numbers) << "\n";
    return 0;
}