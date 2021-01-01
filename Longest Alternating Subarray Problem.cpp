// source : https://www.techiedelight.com/longest-alternating-subarray-problem/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print(vector<int> &v, int l, int r){
    for(int i = l; i <= r; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void findLongestSubArray(vector<int> &v){
    int maxLen = 1;
    int endIndex = 0;
    int currLen = 1;
    for(int i = 0; i < v.size(); i++){
        if(v[i] * v[i - 1] < 0){
            currLen++;
            if(currLen > maxLen){
                maxLen = currLen;
                endIndex = i;
            }
        }
        else{
            currLen = 1;
        }
    }
    cout << "The Longest Alternative Sub-Array is : ";
    print(v, endIndex - maxLen + 1, endIndex);
}
int main(){
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    findLongestSubArray(v);
    return 0;
}

