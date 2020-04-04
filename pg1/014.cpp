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
    vector<int> Len(N, 0), Sum(N, 0);
    Len[0] = 1;
    Sum[0] = vec[0];
    for(int i = 1; i < N; i++)
    {
        if(Sum[i - 1] <= 0){
            Len[i] = Len[i - 1] + 1;
            Sum[i] = Sum[i - 1] + vec[i];
        }
        else{
            Len[i] = 1;
            Sum[i] = vec[i];
        }
    }
    int maxLen = 0;
    for(int i = 0; i < N; i++)
    {
        int sum = Sum[i], idx = i - Len[i];
        while(idx >= 0){
            if(sum + Sum[idx] <= K){
                sum += Sum[idx];
                idx = idx - Len[idx];
            }
            else break;
        }
        if(sum <= K && maxLen < i - idx){
            maxLen = i - idx;
        }
    }
    cout << maxLen << endl;
    return 0;
}