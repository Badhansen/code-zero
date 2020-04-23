#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() {
    set<int> a = {2, 4, 6, 8};
    cout <<
        // greater or equal, but no equal element
        *a.lower_bound(5) << "\n" <<
        // greater or equal, finds equal element
        *a.lower_bound(6) << "\n" <<
        // strictly greater
        *a.upper_bound(5) << "\n" <<
        // strictly greater, so ignores equal element
        *a.upper_bound(6) << "\n";

    cout << binary_search(a.begin(), a.end(), 8) << endl;
}
