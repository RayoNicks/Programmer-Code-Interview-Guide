#include <iostream>
#include <vector>
#include <climits>

#define MOD (int)(1e9+7)

using namespace std;

int main()
{
    int N, M, K, P;
    cin >> N >> M >> K >> P;
    vector<int> vec(N, 0);
    vec[M - 1] = 1;
    for(int k = 0; k < K; k++)
    {
        vector<int> vecTmp(N);
        vecTmp[0] = vec[1];
        for(int n = 1; n < N - 1; n++)
        {
            vecTmp[n] = (vec[n - 1] % MOD + vec[n + 1] % MOD) % MOD;
        }
        vecTmp[N - 1] = vec[N - 2];
        vec = vecTmp;
    }
    cout << vec[P - 1] << endl;
    return 0;
}