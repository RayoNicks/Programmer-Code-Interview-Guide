#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> Matrix;
    for(int i = 0; i < N; i++)
    {
        Matrix.push_back(vector<int>(M));
        for(int j = 0; j < M; j++)
        {
            cin >> Matrix[i][j];
        }
    }
    bool bFind = false;
    size_t i = 0, j = M;
    while(i < N && j > 0){
        if(K < Matrix[i][j - 1]) j--;
        else if(K > Matrix[i][j - 1]) i++;
        else{
            bFind = true;
            break;
        }
    }
    if(bFind) cout << "Yes" << endl;
    else cout << "No" << endl;
}