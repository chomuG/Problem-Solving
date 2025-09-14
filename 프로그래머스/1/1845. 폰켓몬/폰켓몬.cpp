#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> types;
    int answer = nums.size()/2;
    for(int n : nums){
        types.insert(n);
    }
    if(types.size()<answer){
        answer=types.size();
    }
    return answer;
}