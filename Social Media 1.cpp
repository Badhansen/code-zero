#include <iostream>
#include <cassert> 
#include <cstdio>

using namespace std;

#define MAX_TIMELINE_LENGTH 500
#define MIN(A, B) (((A) < (B)) ? (A) : (B))

#define USER 1001
#define MAX_TWEETS 1000001
#define MAX_TWEETS_POST 350000
////////////////////////////////////////////////////////////////

bool user[USER];
int follow_count[USER];
bool follow[USER][USER];
bool tweet[MAX_TWEETS];

///////////////////////////////////////////////////////////////
typedef struct Node{
    double tweet_rank;
    int tweet_id;
    Node* next;
}Node;
Node *user_tweet[USER];
Node pool[MAX_TWEETS_POST];
int pool_index;
Node* createNode(double tr, int tw){
    Node* newNode = &pool[pool_index++];
    newNode->tweet_rank = tr;
    newNode->tweet_id = tw;
    newNode->next = NULL;
    return newNode;
}
Node* add(Node* root, double tr, int tw){
    if(root == NULL){
        return createNode(tr, tw);
    }
    Node* t = createNode(tr, tw);
    t->next = root;
    root = t;
    return root;
}

///////////////////////////////////////////////////////////////
double getTweetRank(int timestamp, int followerCount) {
    return timestamp * (0.8 + 0.2 * MIN(followerCount / 10.0, 2.0));
}

void init() {
    pool_index = 0;
    for(int i = 0; i < USER; i++){
        user[i] = false;
        follow_count[i] = 0;
        user_tweet[i] = NULL;
        for(int j = 0; j < USER; j++){
            follow[i][j] = false;
        }
    }
    for(int i = 0; i < MAX_TWEETS; i++){
        tweet[i] = false;
    }
}

int createUser(int userID, const char* name) {
    if(user[userID]){
        return -1;
    }
    user[userID] = true;
    return 0;
}

void followUser(int followerID, int followeeID) {
    if(follow[followerID][followeeID]){
        return;
    }
    follow[followerID][followeeID] = true;
    follow_count[followeeID]++;
}

int createTweet(int tweetID, int userID, int timestamp, const char* tweet_str) {
    if(tweet[tweetID]){
        return -1;
    }
    tweet[tweetID] = true;
    double rank = getTweetRank(1.00 * timestamp, follow_count[userID]);
    user_tweet[userID] = add(user_tweet[userID], rank, tweetID);
    return 0;
}
template<typename T> void Swap(T *a, T *b) {
    T t = *a;
    *a = *b;
    *b = t;
}

double answer_tweet_rank[MAX_TIMELINE_LENGTH + 1];
int answer_tweet_id[MAX_TIMELINE_LENGTH + 1];
int gk;

bool sort(double tweer_rank, int tweetID){
    bool flag = true;
    int id = MIN(gk, MAX_TIMELINE_LENGTH);
    gk = id + 1;
    answer_tweet_rank[id] = tweer_rank;
    answer_tweet_id[id] = tweetID;
    for(int i = id; i > 0; i--){
        if(answer_tweet_rank[i] > answer_tweet_rank[i - 1]){
            Swap(&answer_tweet_rank[i], &answer_tweet_rank[i - 1]);
            Swap(&answer_tweet_id[i], &answer_tweet_id[i - 1]);
            flag = true;
        }
        else if(answer_tweet_rank[i] == answer_tweet_rank[i - 1]){
            if(answer_tweet_id[i] > answer_tweet_id[i - 1]){
                Swap(&answer_tweet_rank[i], &answer_tweet_rank[i - 1]);
                Swap(&answer_tweet_id[i], &answer_tweet_id[i - 1]);
                flag = true;
            }
            else break;
        }
        else break;
    }
    return flag;
}
int getTimeline(int userID, int res[]) {
    gk = 0;
    for(int i = 0; i < MAX_TIMELINE_LENGTH; i++){
        answer_tweet_rank[i] = -1.0;
        answer_tweet_id[i] = -1;
    }
    for(int i = 0; i < USER; i++){
        if(follow[userID][i]){
            Node* curr = user_tweet[i];
            while(curr){
                double tr = curr->tweet_rank;
                int tw = curr->tweet_id;
                bool flag = sort(tr, tw);
                if(gk > 500){
                    if(flag == false){
                        break;
                    }
                }
                curr = curr->next;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; answer_tweet_id[i] != -1 && cnt < 500; i++){
        res[i] = answer_tweet_id[i];
        cnt++;
    }
    return cnt;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        init();
        int N;
        cin >> N;
        while (N--) {
            int event;
            cin >> event;
            if (event == 1) {
                int user_id;
                string user_name;
                cin >> user_id;
                getline(cin, user_name);
                int create_user_result = createUser(user_id, user_name.c_str());
                cout << create_user_result << endl;
            }
            else if (event == 2) {
                int follower, followee;
                cin >> follower;
                cin >> followee;
                followUser(follower, followee);
            }
            else if (event == 3) {
                int tweet_id, user_id, timestamp;
                string tweet_str;
                cin >> tweet_id;
                cin >> user_id;
                cin >> timestamp;
                getline(cin, tweet_str);
                int create_tweet_result = createTweet(tweet_id, user_id, timestamp, tweet_str.c_str());
                cout << create_tweet_result << endl;
            }
            else if (event == 4) {
                int user_id;
                int timeline_result[MAX_TIMELINE_LENGTH];
                cin >> user_id;
                int timeline_size = getTimeline(user_id, timeline_result);
                cout << "[";
                for (int i = 0; i < timeline_size - 1; i++) {
                    cout << timeline_result[i] << ", ";
                }
                if (timeline_size > 0)
                    cout << timeline_result[timeline_size - 1];
                cout << "]" << endl;
            }
            else {
                assert(false);
            }
        }
    }
    return 0;
}

