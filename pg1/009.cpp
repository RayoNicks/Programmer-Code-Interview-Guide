#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N, K, sum = 0;
    cin >> N >> K;
    vector<int> vec(N);
    map<int, int> Sum;
    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    int maxLength = 0;
    map<int, int>::iterator iter;
    Sum[0] = 0;
    for(int i = 0; i < N; i++)
    {
        sum += vec[i];
        if((iter = Sum.find(sum - K)) != Sum.end()){
            if(maxLength < i + 1 - iter->second){
                maxLength = i + 1 - iter->second;
            }
        }
        if((iter = Sum.find(sum)) == Sum.end()){
            Sum[sum] = i + 1;
        }
    }
    cout << maxLength << endl;
    return 0;
}