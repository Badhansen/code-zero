// source: 1. https://www.techiedelight.com/find-minimum-number-deletions-convert-string-into-palindrome/
//         2. https://codeforces.com/blog/entry/21853
#include<bits/stdc++.h>
#include <string>
using namespace std;
/*

int minDeletions(string str, int i, int j){
    if(i >= j)
        return 0;
    if(str[i] == str[j])
        return minDeletions(str, i + 1, j + 1);
    return 1 + min(minDeletions(str, i + 1, j), minDeletions(str, i, j + 1));
}

*/
struct HASH{
    size_t operator()(const pair<int,int> &x) const{
        return (size_t) x.first * 37U + (size_t) x.second;
    }
};
int minDeletions(string str, int i, int j, auto &lookup){
    if(i >= j)
        return 0;
    if(lookup.find({i, j}) == lookup.end()){
        if(str[i] == str[j]){
            lookup[{i, j}] = minDeletions(str, i + 1, j - 1, lookup);
        }
        else{
            lookup[{i, j}] = 1 + min(minDeletions(str, i + 1, j, lookup),
                                     minDeletions(str, i, j - 1, lookup));
        }
    }
    return lookup[{i, j}];
}

int main(){

    string X = "ACBCDBAA";
	int n = X.length();
	unordered_map<pair<int, int>, int, HASH> lookup;
	cout << "The minimum number of deletions required are " <<
		minDeletions(X, 0, n - 1, lookup);
    return 0;
}
