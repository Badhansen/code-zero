#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        bool flag = false;
        for(int x = 0; !flag && x <= 334; x++){
            for(int y = 0; !flag && y <= 200; y++){
                int z = n - 3 * x - 5 * y;
                if(z < 0) continue;
                if(z % 7 == 0){
                    printf("%d %d %d\n", x, y, z / 7);
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            printf("-1\n");
        }
    }
    return 0;
}

