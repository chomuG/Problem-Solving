#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, zeroCnt = 0, stage = 0, start = 0;  // 변수들 초기화
bool visited[1001];
vector<int> belt;

int main()
{
    cin >> n >> k;
    belt.assign(2 * n, 0);
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> belt[i];
    }
    
    while (zeroCnt < k)
    {
        stage++;
        
        // 1. 1칸 회전
        start = (2 * n + start - 1) % (2 * n);
        
        // n번칸 로봇 있으면 내림
        visited[(start + n - 1) % (2 * n)] = false;
        
        // 2. 로봇 이동 (내리는 위치에 가까운 로봇부터)
        for (int i = n - 2; i >= 0; --i) {  // n-1번은 내리는 위치이므로 n-2부터
            int cur = (start + i) % (2 * n);
            int next = (start + i + 1) % (2 * n);
            
            if (visited[cur] && !visited[next] && belt[next] > 0) {
                visited[cur] = false;
                visited[next] = true;
                belt[next]--;
                if (belt[next] == 0) zeroCnt++;
            }
        }
        
        // n번칸 로봇 있으면 내림
        visited[(start + n - 1) % (2 * n)] = false;
        
        // 3. 로봇 올리기
        if (belt[start] > 0 && !visited[start])
        {
            visited[start] = true;
            belt[start]--;
            if (belt[start] == 0) zeroCnt++;
        }
    }
    
    cout << stage << "\n";
    return 0;
}