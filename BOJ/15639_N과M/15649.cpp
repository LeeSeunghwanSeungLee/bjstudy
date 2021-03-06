#include <iostream>
#include <vector>


using namespace std;

//전역변수
int N, M;
vector<bool> check;
vector<int> ans;

void act_Recur(int depth, int boundary, int num_boundary){
    if (depth >= boundary) {
        for(int i =0; i < boundary; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= num_boundary; i++){
        if(check[i] != true){
            ans.push_back(i);
            check[i] = true;
            act_Recur(depth + 1, boundary, num_boundary);
            check[i] = false;
            ans.pop_back();
        }
        continue;
    } 
}


int main(void){
    //N 과 M을 입력받는다
    cin >> N >> M;

    //vector<bool> check 를 생성한다
    for(int i = 0; i <= N; i++){
        check.push_back(false);
    }
    act_Recur(0, M, N);

    return 0;
}   