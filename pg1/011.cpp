#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N, diff = 0;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    map<int, int> Diff;
    map<int, int>::iterator iter;
    Diff[0] = 0;
    int maxLength = 0;
    for(int i = 0; i < N; i++)
    {
        if(vec[i] == 1) diff++;
        else diff--;
        if((iter = Diff.find(diff)) != Diff.end()){
            if(maxLength < i + 1 - iter->second){
                maxLength = i + 1 - iter->second;
            }
        }
        if((iter = Diff.find(diff)) == Diff.end()){
            Diff[diff] = i + 1;
        }
    }
    cout << maxLength << endl;
    return 0;
}