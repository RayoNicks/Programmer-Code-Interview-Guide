#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    vector<vector<int>> Score(n + 1, vector<int>(n + 1, 0));
    int score;
    for(int i = 1; i <= n; i++)
    {
        for(int begin = 0; begin + i <= n; begin++)
        {
            int end = begin + i;
            int left = begin == 0 ? 1 : vec[begin - 1];
            int right = end == n ? 1 : vec[end];
            for(int s = begin; s < end; s++)
            {
                score = left * vec[s] * right + Score[begin][s] + Score[s + 1][end];
                if(score > Score[begin][end]){
                    Score[begin][end] = score;
                }
            }
        }
    }
    cout << Score[0][n] << endl;
    return 0;
}