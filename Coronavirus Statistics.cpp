#include<stdio.h>

#define MAX_LENGTH 10
#define MAX_DAYS 5000
#define TOTAL_COUNTRY 5000
#define Long long long

using namespace std;


/////////////////////////////////////////////

typedef struct Days{
    int day;
    int cases = 0;
    int recoveries = 0;
    int deaths = 0;
}Days;

typedef struct Node{
    char country[MAX_LENGTH];
    Days days[20];
    int days_count = 0;
}Node;

int mstrlen(char a[]){
    int i = 0;
    while (a[i] != '\0') i++;
    return i;
}

bool mstrcmp(const char *a, const char *b){
    int i;
    for (i = 0; a[i] != '\0'; i++){
        if (a[i] != b[i])
        return false;
    }
    return (a[i] - b[i]) == 0 ? true : false;
}

void mstrcpy(char *dest, const char *src){
    int i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
}

Node tb[TOTAL_COUNTRY];
Node wr;

int getHash(char *country){
    int hsh = 0, i = 0;
    while(country[i] != '\0'){
        hsh += (country[i] - 'A');
        i++;
    }
    return hsh % TOTAL_COUNTRY;
}

int searchHash(char *country){
    int index = getHash(country);
    if(index < 0) index += TOTAL_COUNTRY;
    while(tb[index].country[0] != '\0'){
        if(mstrcmp(tb[index].country, country)){
            return index;
        }
        index++;
        if(index == TOTAL_COUNTRY) index = 0;
    }
    return index;
}

/////////////////////////////////////////////

void init(){
    for(int i = 0; i < TOTAL_COUNTRY; i++){
        tb[i].country[0] = '\0';
        tb[i].days_count = 0;
    }
}

void Add(char *country, int dy, int cs, int rs, int ds){
    int hsh = searchHash(country);
    mstrcpy(tb[hsh].country, country);
    tb[hsh].days[tb[hsh].days_count].day = dy;
    tb[hsh].days[tb[hsh].days_count].cases = cs;
    tb[hsh].days[tb[hsh].days_count].recoveries = rs;
    tb[hsh].days[tb[hsh].days_count].deaths = ds;
    tb[hsh].days_count++;

    wr.days[wr.days_count].day = dy;
    wr.days[wr.days_count].cases = cs;
    wr.days[wr.days_count].recoveries = rs;
    wr.days[wr.days_count].deaths = ds;
    wr.days_count++;
}

Long QueryNumber(char *country, char type, int day){
    Long answer = 0;
    if(mstrcmp(country, "WORLD")){
        if(type == 'C'){
            for(int i = 0; i < wr.days_count; i++){
                if(wr.days[i].day > day)
                    break;
                answer += wr.days[i].cases;
            }
        }
        else if(type == 'R'){
            for(int i = 0; i < wr.days_count; i++){
                if(wr.days[i].day > day)
                    break;
                answer += wr.days[i].recoveries;
            }
        }
        else{
            for(int i = 0; i < wr.days_count; i++){
                if(wr.days[i].day > day)
                    break;
                answer += wr.days[i].deaths;
            }
        }
        return answer;
    }
    int hsh = searchHash(country);
    if(type == 'C'){
        for(int i = 0; i < tb[hsh].days_count; i++){
            if(tb[hsh].days[i].day > day)
                break;
            answer += tb[hsh].days[i].cases;
        }
    }
    else if(type == 'R'){
        for(int i = 0; i < tb[hsh].days_count; i++){
            if(tb[hsh].days[i].day > day)
                break;
            answer += tb[hsh].days[i].recoveries;
        }
    }
    else{
        for(int i = 0; i < tb[hsh].days_count; i++){
            if(tb[hsh].days[i].day > day)
                break;
            answer += tb[hsh].days[i].deaths;
        }
    }
    return answer;
}

Long QueryDays(char *country, char type, Long number){
    Long answer = 0;
    if(mstrcmp(country, "WORLD")){
        if(type == 'C'){
            for(int i = 0; i < wr.days_count; i++){
                answer += wr.days[i].cases;
                if(answer >= number){
                    return wr.days[i].day;
                }
            }
        }
        else if(type == 'R'){
            for(int i = 0; i < wr.days_count; i++){
                answer += wr.days[i].recoveries;
                if(answer >= number){
                    return wr.days[i].day;
                }
            }
        }
        else{
            for(int i = 0; i < wr.days_count; i++){
                answer += wr.days[i].deaths;
                if(answer >= number){
                    return wr.days[i].day;
                }
            }
        }
        return -1;
    }
    int hsh = searchHash(country);
    if(type == 'C'){
        for(int i = 0; i < tb[hsh].days_count; i++){
            answer += tb[hsh].days[i].cases;
            if(answer >= number){
                return tb[hsh].days[i].day;
            }
        }
    }
    else if(type == 'R'){
        for(int i = 0; i < tb[hsh].days_count; i++){
            answer += tb[hsh].days[i].recoveries;
            if(answer >= number){
                return tb[hsh].days[i].day;
            }
        }
    }
    else{
        for(int i = 0; i < tb[hsh].days_count; i++){
            answer += tb[hsh].days[i].deaths;
            if(answer >= number){
                return tb[hsh].days[i].day;
            }
        }
    }
    return -1;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, q;
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d", &q);
        while(q--){
            char type[10];
            char con[10], day[10], num[20];
            scanf("%s%s", type, con);
            if(type[0] == 'A'){
                int dy, cs, rs, ds;
                scanf("%d%d%d%d", &dy, &cs, &rs, &ds);
                Add(con, dy, cs, rs, ds);
            }
            else{
                char ty[10];
                scanf("%s%s%s", ty, day, num);
                if(day[0] == '?'){
                    int len = mstrlen(num);
                    Long number = 0;
                    for(int i = 0; i < len; i++){
                        number = number * 10 + (int)(num[i] - '0');
                    }
                    Long answer = QueryDays(con, ty[0], number);
                    printf("%lld\n", answer);
                }
                else{
                    int len = mstrlen(day);
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
