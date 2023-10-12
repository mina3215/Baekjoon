#include <string>
#include <bits/stdc++.h>

using namespace std;

int nums[]={0,1,2,3,4,5,4,3,2,1,0};


int solution(int storey) {
    string s = to_string(storey);
    int up = 0;
    int answer = 0;
    for(int i = s.length()-1; i>=0; i--){
        int a = int(s[i])-int('0') + up;
        if(a >=6){
            up = 1;
            answer += nums[a];
        }else if(i>0&&a==5&&int(s[i-1]-'0')>=5){
            up = 1;
            answer += nums[a];
            
        }else{
            up = 0;
            answer += nums[a];
        }
    }
    answer += up;
    return answer;
}