#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, maxNum=-1000000000, minNum=1000000000;
char operators[4]={'+','-','*','/'};
vector<int> arr;
vector<bool> used;
vector<char> opArr;

int calculate(int a, int b, char op){
    int ret=0;
    switch (op)
    {
    case '+':
        ret=a+b;
        break;
    case '-':
        ret=a-b;
        break;
    case '*':
        ret=a*b;
        break;
    case '/':
        ret=a/b;
        break;
    default:
        break;
    }

    return ret;
}

void findMaxMinNumber(int index, int curNum){
    int nextNum=0;
    if(index >= n-1){
        maxNum=max(maxNum, curNum);
        minNum=min(minNum, curNum);
        return;
    }

    

    for(int i=0; i<opArr.size(); ++i){
        if(!used[i]){
            used[i]=true;
            nextNum = calculate(curNum, arr[index+1], opArr[i]);
            findMaxMinNumber(index+1,nextNum);
            used[i]=false;
        }
    }
}

int main(){
    cin>>n;
    int in;
    used.resize(n-1, false);
    for(int i=0; i<n; ++i){
        cin>>in;
        arr.push_back(in);
    }
    for(int i=0; i<4; ++i){//+, -, x, /
        cin>>in;
        for(int j=0; j<in; ++j){
            opArr.push_back(operators[i]);
        }
    }

    for(int i=0; i<opArr.size(); ++i){
        used[i]=true;
        int nextNum = calculate(arr[0], arr[1], opArr[i]);
        findMaxMinNumber(1, nextNum);
        used[i]=false;
    }

    cout<<maxNum<<endl;
    cout<<minNum<<endl;
}