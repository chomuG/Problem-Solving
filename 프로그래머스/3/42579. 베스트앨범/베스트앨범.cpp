#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string,int> totalPlays;
    unordered_map<string, vector<pair<int,int>>> songs;
    // 장르별 합
    for(int i=0; i<genres.size(); ++i){
        totalPlays[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});
    }

    // 재생수 내림차순, 동점 시 인덱스 오름차순 정렬
    for(auto &kv : songs){
        auto &vec = kv.second;
        sort(vec.begin(), vec.end(),
             [](auto &a, auto &b){
                 if(a.first != b.first) return a.first > b.first;
                 return a.second < b.second;
             });
    }

    // 총 재생수 내림차순 정렬
    vector<pair<string,int>> genreOrder;
    for(auto &kv : totalPlays)
        genreOrder.push_back({kv.first, kv.second});
    sort(genreOrder.begin(), genreOrder.end(),
         [](auto &a, auto &b){
             return a.second > b.second;
         });

    vector<int> answer;
    for(auto &g : genreOrder){
        auto &vec = songs[g.first];
        answer.push_back(vec[0].second);
        if(vec.size() > 1)
            answer.push_back(vec[1].second);
    }
    return answer;
}