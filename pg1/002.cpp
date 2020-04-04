#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<int> vec(N, 0);
    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    int len = 1, min, max;
    for(int i = 0; i < N; i++)
    {
        min = max = vec[i];
        for(int j = i + 1; j < N; j++)
        {
            if(vec[j] < min) min = vec[j];
            if(vec[j] > max) max = vec[j];
            if(max - min == j - i){
                if(len < j - i + 1){
                    len = j - i + 1;
                }
            }
        }
    }
    cout << len << endl;
}