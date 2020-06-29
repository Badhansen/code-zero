// AC
// Problem Link: https://www.hackerrank.com/contests/swc-june2020/challenges/pandemic-1/problem
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

/// *************************************************************************** ///

#define MAX         50001
#define MAX_LENGTH  55
#define MAX_AGE     201
#define mod         50000
#define base        31

/// *************************************************************************** ///

void str_copy(char *dest, const char *src){
    int i = 0;
    while(src[i]){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
bool str_compare(const char *a, const char *b){
    int i;
    for(i = 0; a[i] && b[i]; i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    if(a[i] == '\0' && b[i] == '\0'){
        return true;
    }
    return false;
}

/// *************************************************************************** ///

typedef struct Hash{
    char key[MAX_LENGTH];
    int Age[MAX_AGE];
}Hash;
typedef struct DataBase{
    char id[MAX_LENGTH];
    char address[MAX_LENGTH];
    char district[MAX_LENGTH];
    int age;
    bool isDelete;
}DataBase;

/// *************************************************************************** ///

DataBase data_base[MAX];
Hash Address[MAX];
Hash District[MAX];
int Id[MAX];
int db_index;

/// *************************************************************************** ///

int compute_hash(const char *src){
    int hash = 0;
    for(int i = 0; src[i]; i++){
        hash = (1ll * hash * base) % mod + src[i];
        hash %= mod;
    }
    return hash;
}
bool find_id_hash(const char *src, int *hash_data){
    int hash = compute_hash(src);
    while(Id[hash] != -1){
        if(str_compare(data_base[Id[hash]].id, src)){
            *hash_data = hash;
            return true;
        }
        hash++;
        if(hash == MAX){
            hash = 0;
        }
    }
    *hash_data = hash;
    return false;
}
bool find_address_hash(const char *src, int *hash_data){
    int hash = compute_hash(src);
    while(Address[hash].key[0] != 0){
        if(str_compare(Address[hash].key, src)){
            *hash_data = hash;
            return true;
        }
        hash++;
        if(hash == MAX){
            hash = 0;
        }
    }
    *hash_data = hash;
    return false;
}
bool find_district_hash(const char *src, int *hash_data){
    int hash = compute_hash(src);
    while(District[hash].key[0] != 0){
        if(str_compare(District[hash].key, src)){
            *hash_data = hash;
            return true;
        }
        hash++;
        if(hash == MAX){
            hash = 0;
        }
    }
    *hash_data = hash;
    return false;
}

/// *************************************************************************** ///

void init()
{
    db_index = 1;
    for(int i = 0; i < MAX; i++){
        Id[i] = -1;
        Address[i].key[0] = 0;
        District[i].key[0] = 0;
        for(int j = 0; j < MAX_AGE; j++){
            Address[i].Age[j] = 0;
            District[i].Age[j] = 0;
        }
    }
}

void addPatient(char id[], char address[], int age)
{
    ///////////////////////////////////////////

    int pos = 0;
    for(int i = 0; address[i]; i++){
        if(address[i] == ','){ 
            pos = i + 1;
            break;
        }
    }
    char dist[MAX_LENGTH];
    int i = 0;
    while(address[pos]){
        dist[i++] = address[pos++];
    }
    dist[i] = 0;

    ///////////////////////////////////////////

    int hash = 0;
    bool flag = find_id_hash(id, &hash);
    if(flag == false){
        Id[hash] = db_index;
        str_copy(data_base[db_index].id, id);
        str_copy(data_base[db_index].address, address);
        str_copy(data_base[db_index].district, dist);
        data_base[db_index].age = age;
        data_base[db_index].isDelete = false;

        hash = 0;
        flag = find_address_hash(address, &hash);
        if(flag == false){
            str_copy(Address[hash].key, address);
            Address[hash].Age[age]++;
        }
        else{
            Address[hash].Age[age]++;
        }

        hash = 0;
        flag = find_district_hash(dist, &hash);
        if(flag == false){
            str_copy(District[hash].key, dist);
            District[hash].Age[age]++;
        }
        else{
            District[hash].Age[age]++;
        }

        db_index++;
    }
    else{
        if(data_base[Id[hash]].isDelete){
            Id[hash] = db_index;
            str_copy(data_base[db_index].id, id);
            str_copy(data_base[db_index].address, address);
            str_copy(data_base[db_index].district, dist);
            data_base[db_index].age = age;
            data_base[db_index].isDelete = false;

            hash = 0;
            flag = find_address_hash(address, &hash);
            if(flag == false){
                str_copy(Address[hash].key, address);
                Address[hash].Age[age]++;
            }
            else{
                Address[hash].Age[age]++;
            }
            
            hash = 0;
            flag = find_district_hash(dist, &hash);
            if(flag == false){
                str_copy(District[hash].key, dist);
                District[hash].Age[age]++;
            }
            else{
                District[hash].Age[age]++;
            }
            db_index++;
        }
    }
}


void removePatient(char id[])
{
    int hash = 0;
    bool flag = find_id_hash(id, &hash);
    if(flag == false){
        return;
    }
    else{
        int ind = Id[hash];
        if(data_base[ind].isDelete == false){
            data_base[ind].isDelete = true;
            hash = 0;
            flag = find_address_hash(data_base[ind].address, &hash);
            if(flag){
                Address[hash].Age[data_base[ind].age]--;
            }

            hash = 0;
            flag = find_district_hash(data_base[ind].district, &hash);
            if(flag){
                District[hash].Age[data_base[ind].age]--;
            }
        }
    }
}

int numberOfPatient(char inArea[], int fromAge, int toAge)
{
    int total = 0;
    int hash = 0;
    bool flag = false;
    for(int i = 0; inArea[i]; i++){
        if(inArea[i] == ','){
            flag = true;
            break;
        }
    }
    if(flag){
        hash = 0;
        flag = find_address_hash(inArea, &hash);
        for(int i = fromAge; i < toAge; i++){
            total += Address[hash].Age[i];
        }
        return total;
    }
    else{
        hash = 0;
        flag = find_district_hash(inArea, &hash);
        for(int i = fromAge; i < toAge; i++){
            total += District[hash].Age[i];
        }
        return total;
    }
    return total;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, Q, queryType;
    char id[13],address[42];
    int  age, start, end;

    scanf("%d", &T);

    for (int TC = 1; TC <= T; TC++)
    {
        init();

        scanf("%d", &Q);
        while (Q--)
        {
            scanf("%d", &queryType);
      
            if (queryType == 1)
            {
                scanf("%s %s %d", id, address, &age);
                addPatient(id, address, age);
            }
            else if (queryType == 2)
            {
                scanf("%s", id);
                removePatient(id);
            }
            else if (queryType == 3)
            {
                scanf("%s %d %d", address, &start, &end);
                int val = numberOfPatient(address, start, end);
                printf("%d\n",val);
            }
        }
    }
    return 0;
}