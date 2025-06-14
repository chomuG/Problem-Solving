#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> formulas, equations, answers;
bool exactly;
int radix=-1;

bool isFormula(string formula){
    if(formula[formula.size()-1]=='X')
        return false;

    return true;
}

//진수 판별
void checkRadix(){
    for(string formula : formulas){
        string num="";
        vector<string> nums;
        char op;
        //숫자 및 연산자 분리
        for(int i=0; i<formula.size(); ++i){
            char cur = formula[i];
            if(isdigit(cur)){
                num+=cur;
            }else{
                if(num!=""){
                    nums.push_back(num);
                    num="";
                }
                if(cur=='-' || cur=='+'){
                    op=cur;
                }
            }
            if(i==formula.size()-1){
                nums.push_back(num);
            }
        }
        
        //수식 계산을 통한 최소 진수 판별
        int a=stoi(nums[0]), b=stoi(nums[1]), c=stoi(nums[2]);
        if(op=='+'){
            //만약 자릿수가 넘어가면 확실히 몇진수인지 확인 가능
            //일의 자리 계산
            if((a%10)+(b%10)!=(c%10)){
                exactly=true;
                radix=(a%10)+(b%10)-(c%10);
                return;
            }
            //십의 자리 계산
            if(((a/10)%10)+((b/10)%10)!=((c/10)%10)){
                exactly=true;
                radix=((a/10)%10)+((b/10)%10)-((c/10)%10);
                return;
            }
            //둘 다 안되면 최소 radix 갱신
            for(int i=0; i<nums.size(); ++i){
                int tmp =stoi(nums[i]);
                while(tmp>0){
                    radix = max(radix, tmp%10+1);
                    tmp/=10;
                }
            }
        }else{
            //뺄 때 자릿수가 넘어가면 정확한 자릿수 확인 가능
            //일의 자리만 계산
            if((a%10)-(b%10)!=(c%10)){
                exactly=true;
                radix=-(a%10)+(b%10)+(c%10);
                return;
            }
            
            //최소 radix 갱신
            for(int i=0; i<nums.size(); ++i){
                int tmp =stoi(nums[i]);
                while(tmp>0){
                    radix = max(radix, tmp%10+1);
                    tmp/=10;
                }
            }
        }
    }
    
    for(string formula : equations){
        string num="";
        vector<string> nums;
        char op;
        //숫자 및 연산자 분리
        for(int i=0; i<formula.size(); ++i){
            char cur = formula[i];
            if(isdigit(cur)){
                num+=cur;
            }else{
                if(num!=""){
                    nums.push_back(num);
                    num="";
                }
                if(cur=='-' || cur=='+'){
                    op=cur;
                }
            }
        }
        
        //최소 radix 갱신
        for(int i=0; i<nums.size(); ++i){
            int tmp =stoi(nums[i]);
            while(tmp>0){
                radix = max(radix, tmp%10+1);
                tmp/=10;
            }
        }
    }
    if(radix==9)
        exactly=true;
}

void calculateEquation(){
    for(string equation : equations){
        int answer=0;
        string num="";
        vector<string> nums;
        char op;
        //숫자 및 연산자 분리
        for(int i=0; i<equation.size(); ++i){
            char cur = equation[i];
            if(isdigit(cur)){
                num+=cur;
            }else{
                if(num!=""){
                    nums.push_back(num);
                    num="";
                }
                if(cur=='-' || cur=='+'){
                    op=cur;
                }
            }
        }
        int a=stoi(nums[0]), b=stoi(nums[1]), one=0, two=0, thr=0;
        if(exactly){
            if(op=='+'){
                //일의 자리 계산
                if(a%10+b%10>=radix){
                    one = a%10+b%10-radix;
                    two++;
                }else{
                    one = a%10+b%10;
                }
                a/=10;
                b/=10;
                //십의 자리 계산
                if(two+a%10+b%10>=radix){
                    two= two+a%10+b%10-radix;
                    thr++;
                }else{
                    two+= (a%10+b%10);
                }
            }else{
                if(a%10-b%10<0){
                    one = radix+(a%10-b%10);
                    two--;
                }else{
                    one = a%10-b%10;
                }
                a/=10;
                b/=10;
                two+= ((a%10)-(b%10));
            }
            answer= (100*thr)+(10*two)+(one);
            string tmp = to_string(answer);
            answers.push_back(equation.substr(0, equation.size()-1)+tmp);
        }else{
            if(op=='+'){
                //일의 자리 계산
                if(a%10+b%10>=radix){
                    answers.push_back(equation.substr(0, equation.size()-1)+'?');
                    continue;
                }else{
                    one = a%10+b%10;
                }
                a/=10;
                b/=10;
                //십의 자리 계산
                if(a%10+b%10>=radix){
                    answers.push_back(equation.substr(0, equation.size()-1)+'?');
                    continue;
                }else{
                    two+= (a%10+b%10);
                }
            }else{
                if(a%10-b%10<0){
                    answers.push_back(equation.substr(0, equation.size()-1)+'?');
                    continue;
                }else{
                    one = a%10-b%10;
                }
                a/=10;
                b/=10;
                two+= ((a%10)-(b%10));
            }
            answer= (100*thr)+(10*two)+(one);
            string tmp = to_string(answer);
            answers.push_back(equation.substr(0, equation.size()-1)+tmp);
        }
    }
}

vector<string> solution(vector<string> expressions) {
    //수식이냐 방정식이냐 구분
    for(string formula : expressions){
        if(isFormula(formula)){
            formulas.push_back(formula);
        }else{
            equations.push_back(formula);
        }
    }
    checkRadix();
    calculateEquation();
    return answers;
}