#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    vector<int> res;
    deque<int> dqIdx;
    dqIdx.push_back(0);
    for(int idx = 1; idx < n; idx++)
    {
        if(dqIdx.front() <= idx - w){
            dqIdx.pop_front();
        }
        while(!dqIdx.empty() && vec[idx] > vec[dqIdx.back()]){
            dqIdx.pop_back();
        }
        dqIdx.push_back(idx);
        if(idx >= w - 1){
            res.push_back(dqIdx.front());
        }
    }
    for_each(res.begin(), res.end(), [vec](const int &maxIdx)->void
             {
                 cout << vec[maxIdx] << ' ';
             });
    cout << endl;
    return 0;
}