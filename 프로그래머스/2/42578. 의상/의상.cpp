#include <string>
#include <vector>
#include <map>

using namespace std;
vector<vector<string>> typeClothes(31, vector<string>(0));
map<string, int> types;
int cnt=1, answer=1;

int solution(vector<vector<string>> clothes) {
    for(vector<string> cloth : clothes){
        if(types[cloth[1]]==0){
            types[cloth[1]]=cnt;
            typeClothes[cnt++].push_back(cloth[0]);
        }else{
            typeClothes[types[cloth[1]]].push_back(cloth[0]);
        }
    }

    for(int i=1; i<cnt; ++i){
        answer*=(typeClothes[i].size()+1);
    }

    return answer-1;
}