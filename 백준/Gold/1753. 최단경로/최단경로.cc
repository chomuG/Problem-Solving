#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int INF = 987654321;
int v, e, k;
vector<vector<pii>> adj; // 인접 리스트: {연결된 노드, 가중치}
vector<int> dist;

void dijkstra(){
    // 우선순위 큐: {거리(-값), 노드번호}
    priority_queue<pii> pq;
    pq.push({0, k});
    
    while (!pq.empty()){
        // 거리가 가장 가까운 노드부터 방문
        pii cur = pq.top();
        pq.pop();
        int curNode = cur.second, curWeight = -cur.first;
        
        // 이미 더 짧은 경로를 찾았다면 스킵
        if(curWeight > dist[curNode]) continue;
        
        // 현재 노드와 연결된 노드들만 방문
        for(auto& next : adj[curNode]) {
            int nextNode = next.first;
            int weight = next.second;
            
            // 현재 노드를 경유하는 것이 더 가까우면 갱신
            if(curWeight + weight < dist[nextNode]) {
                dist[nextNode] = curWeight + weight;
                pq.push({-dist[nextNode], nextNode});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> v >> e;
    adj.resize(v);
    dist.assign(v, INF);
    
    cin >> k;
    k--;
    
    // 인접 리스트 입력
    for(int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // 0-인덱스 기반으로 변환
        
        // 같은 간선이 여러 번 주어지는 경우 처리
        bool found = false;
        for(auto& p : adj[u]) {
            if(p.first == v) {
                p.second = min(p.second, w);
                found = true;
                break;
            }
        }
        
        if(!found) {
            adj[u].push_back({v, w});
        }
    }
    
    // 시작 노드 거리 초기화
    dist[k] = 0;
    
    // 다익스트라 알고리즘 실행
    dijkstra();
    
    // 결과 출력
    for(int d : dist) {
        if(d != INF)
            cout << d << "\n";
        else
            cout << "INF" << "\n";
    }
    
    return 0;
}