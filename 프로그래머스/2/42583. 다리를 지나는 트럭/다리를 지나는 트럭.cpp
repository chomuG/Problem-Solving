#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, weights=0, curTime=0, idx=0;
    deque<pii> onBridge;
    
    while(curTime==0 || !onBridge.empty()){
        curTime++;
        //다 끝난거 내리기
        if(!onBridge.empty() && curTime - onBridge[0].second == bridge_length){
            weights-=onBridge[0].first;
            onBridge.pop_front();
        }
        
        //on 가능한 트럭 올리기.
        if(weights+truck_weights[idx]<= weight && idx<truck_weights.size()){
            onBridge.push_back({truck_weights[idx], curTime});
            weights+=truck_weights[idx];
            idx++;
        }
    }
    
    return curTime;
}