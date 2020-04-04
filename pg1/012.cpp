#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n, aim;
    cin >> n >> aim;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    /*vector<vector<int>> Cnt(n, vector<int>(aim + 1, INT_MAX));
    for(int a = 0; a <= aim; a++)
    {
        if(a % arr[0] == 0){
            Cnt[0][a] = a / arr[0];
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int a = 0; a <= aim; a++)
        {
            Cnt[i][a] = Cnt[i - 1][a];
            if(a >= arr[i]){
                if(Cnt[i][a - arr[i]] != INT_MAX){
                    if(Cnt[i][a] > Cnt[i][a - arr[i]] + 1){
                    Cnt[i][a] = Cnt[i][a - arr[i]] + 1;
                    }
                }
            }
        }
    }
    if(Cnt.back().back() == INT_MAX) cout << -1 << endl;
    else cout << Cnt.back().back() << endl;*/
    vector<int> Cnt(aim + 1, INT_MAX);
    Cnt[0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int a = 0; a <= aim; a++)
        {
            if(a >= arr[i] && Cnt[a - arr[i]] != INT_MAX){
                if(Cnt[a] > Cnt[a - arr[i]] + 1){
                    Cnt[a] = Cnt[a - arr[i]] + 1;
                }
            }
        }
    }
    if(Cnt[aim] == INT_MAX) cout << -1 << endl;
    else cout << Cnt[aim] << endl;
    return 0;
}