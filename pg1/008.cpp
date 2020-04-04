#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    int begin = 0, end = 1;
    int sum = vec[0], maxLen = 0;
    while(end <= N){
        if(sum == K){
            if(maxLen < end - begin){
                maxLen = end - begin;
            }
            sum -= vec[begin++];
        }
        else if(sum < K){
            if(end == N) break;
            sum += vec[end++];
        }
        else{
            sum -= vec[begin++];
        }
    }
    cout << maxLen << endl;
    return 0;
}