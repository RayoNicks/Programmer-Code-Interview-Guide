#include <iostream>
#include <vector>
#include <climits>

#define MOD (int)(1e9 + 7)

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
    vector<int> Cnt(aim + 1, 0);
    Cnt[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int a = 0; a <= aim; a++)
        {
            if(a >= arr[i] && Cnt[a - arr[i]] != INT_MAX){
                Cnt[a] += Cnt[a - arr[i]];
                Cnt[a] %= MOD;
            }
        }
    }
    cout << Cnt[aim] << endl;
    return 0;
}