#include<bits/stdc++.h>
#define Long long long

using namespace std;


/////////////////////////////////////////////
typedef struct Days{
    int day;
    int cases = 0;
    int recoveries = 0;
    int deaths = 0;
}Days;
unordered_map<string, vector<Days>> tb;

/////////////////////////////////////////////

void init(){
    tb.clear();
}

void Add(string country, int dy, int cs, int rs, int ds){
    Days nw;
    nw.day = dy;
    nw.cases = cs;
    nw.recoveries = rs;
    nw.deaths = ds;
    if(tb[country].size() == 0)
        tb[country].push_back(nw);
    else{
        Days a = tb[country].back();
        a.cases += nw.cases;
        a.recoveries += nw.recoveries;
        a.deaths += nw.deaths;

        a.day = nw.day;
        tb[country].push_back(a);
    }
    if(tb["WORLD"].size() == 0){
        tb["WORLD"].push_back(nw);
    }
    else{
        Days a = tb["WORLD"].back();
        a.cases += nw.cases;
        a.recoveries += nw.recoveries;
        a.deaths += nw.deaths;

        a.day = nw.day;
        tb["WORLD"].push_back(a);
    }
}

Long QueryNumber(string country, char type, int day){
    Long answer = 0;
    if(type == 'C'){
        int low = 0, high = tb[country].size() - 1;
        while(high > low){
            int mid = (high + low) / 2;
            if(mid == day){
                return tb[country][mid].cases;
            }
            else if(tb[country][mid].day > day){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return tb[country][low].cases;
    }
    else if(type == 'R'){
        int low = 0, high = tb[country].size() - 1;
        while(high > low){
            int mid = (high + low) / 2;
            if(mid == day){
                return tb[country][mid].recoveries;
            }
            else if(tb[country][mid].day > day){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return tb[country][low].recoveries;
    }
    else{
        int low = 0, high = tb[country].size() - 1;
        while(high > low){
            int mid = (high + low) / 2;
            if(mid == day){
                return tb[country][mid].deaths;
            }
            else if(tb[country][mid].day > day){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return tb[country][low].deaths;
    }
    return answer;
}

Long QueryDays(string country, char type, Long number){
    Long answer = 0;
    if(type == 'C'){
        for(int i = 0; i < tb[country].size(); i++){
            answer += tb[country][i].cases;
            if(answer >= number)
                return tb[country][i].day;
        }
    }
    else if(type == 'R'){
        for(int i = 0; i < tb[country].size(); i++){
            answer += tb[country][i].recoveries;
            if(answer >= number)
                return tb[country][i].day;
        }
    }
    else{
        for(int i = 0; i < tb[country].size(); i++){
            answer += tb[country][i].deaths;
            if(answer >= number)
                return tb[country][i].day;
        }
    }
    return -1;
}

int main(){
    int t, q;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d", &q);
        while(q--){
            string ty, type, con, day, num;
            cin >> type >> con;
            if(type[0] == 'A'){
                int dy, cs, rs, ds;
                cin >> dy >> cs >> rs >> ds;
                Add(con, dy, cs, rs, ds);
            }
            else{
                cin >> ty >> day >> num;
                if(day[0] == '?'){
                    int len = num.size();
                    Long number = 0;
                    for(int i = 0; i < len; i++){
                        number = number * 10 + (int)(num[i] - '0');
                    }
                    Long answer = QueryDays(con, ty[0], number);
                    printf("%lld\n", answer);
                }
                else{
                    int len = day.size();
                    int number = 0;
                    for(int i = 0; i < len; i++){
                        number = number * 10 + (int)(day[i] - '0');
                    }
                    Long answer = QueryNumber(con, ty[0], number);
                    printf("%lld\n", answer);
                }
            }
        }
    }
    return 0;
}
