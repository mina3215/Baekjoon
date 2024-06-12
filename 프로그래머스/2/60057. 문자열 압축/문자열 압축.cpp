#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int min_V = 2e9;

int find_ans(int n, string &s){
    
    vector<int> len ={1};
    int cnt = 1; // 갯수 세기
    string prev = s.substr(0,n);
    
    while(n*cnt<=s.size()){
        string next = s.substr(cnt*n,n);
        if(prev==next){
            len.back()+=1;
        }
        else{
            len.push_back(1);
        }
        cnt++;
        prev = next;
    }
    int ans = s.size()-cnt*n;
    ans+=len.size()*n;
    for(int i=0; i<len.size(); i++){
        if(len[i]>1){
            int c = 0;
            while(len[i]>0){
                len[i]/=10;
                c++;
            }
            ans+=c;
        }
    }
    return ans;
}

int solution(string s) {
    int answer = 0;
    
    for(int i=1; i<=s.size(); i++){
        min_V = min(find_ans(i, s), min_V);
    }
   
    return min_V;
}