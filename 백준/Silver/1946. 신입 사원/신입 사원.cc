#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    vector<pair<int,int>> recruits;
    int T,N;
    cin>>T;
    while(T--){
        int cnt=1, m2;
        
        cin>>N;
        for( int i=0, scr1, scr2; i<N; ++i){
            cin>>scr1>>scr2;
            recruits.push_back(make_pair(scr1,scr2));
        }
        sort(recruits.begin(), recruits.end());
        m2=recruits[0].second;
        for(int i=1; i<N; ++i){
            if(recruits[i].second<m2){
                cnt++;
                m2=recruits[i].second;
            }
        }
        cout<<cnt<<endl;
        recruits.clear();
    }
    return 0;
}
