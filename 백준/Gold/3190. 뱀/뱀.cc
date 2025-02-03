#include <iostream> 
#include <vector>
#include <deque>
using namespace std;
int n, k, l, dx[]={0, 1, 0, -1}, dy[]={1, 0,-1, 0};
deque<deque<int>> board;
deque<pair<int, char>> info, memo;

bool isOutOfRange(int x, int y){//자기자신은 1
    return (x<1 || x>n || y<1 || y>n || board[x][y]==1);
}

int getFinishTime(){
    int timeCnt=0, direct=0;
    int head[2]={1,1}, tail[2]={1,1};//시작위치
    board[1][1]=1;
    while(1){
        int nextX=head[0]+dx[direct], nextY=head[1]+dy[direct];
        timeCnt++;
        if(isOutOfRange(nextX, nextY))
            return timeCnt;
        
        memo.push_back({nextX, nextY});

        if(board[nextX][nextY]==0){// 사과가 없으면 꼬리 갱신
            board[tail[0]][tail[1]]=0;
            tail[0]=memo[0].first;
            tail[1]=memo[0].second;
            memo.pop_front();
        }

        //머리 갱신
        head[0]=nextX;
        head[1]=nextY;

        //보드가 뱀으로 채워짐
        board[nextX][nextY]=1;      
        
        //방향전환 확인
        if(!info.empty()){
            if(info[0].first==timeCnt){
                if(info[0].second=='D'){
                    direct=(direct+5)%4;
                }else{
                    direct=(direct+3)%4;
                }
                info.pop_front();
            }
        }
    }

    return timeCnt;
}

int main(){
    cin>>n>>k;
    board.resize(n+1, deque<int>(n+1, 0));
    for(int i=0; i<k; ++i){
        int x, y;
        cin>>x>>y;
        board[x][y]=2;//사과 위치. 사과는 2
    }
    cin>>l;
    for(int i=0; i<l; ++i){
        int x;
        char c;
        cin>>x>>c;
        info.push_back(make_pair(x, c));
    }

    cout<<getFinishTime();   
}