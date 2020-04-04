#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Matrix[i][j];
        }
    }
    vector<int> height(m, 0);
    int maxOnes = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> vec;
        int idx, ones;
        for (int j = 0; j < m; j++)
        {
            height[j] = Matrix[i][j] == 1 ? height[j] + 1 : 0;
            while (!vec.empty() && height[vec.back()] > height[j]) {
                idx = vec.back();
                vec.pop_back();
                if (vec.empty()) {
                    ones = j * height[idx];
                }
                else {
                    ones = (j - (vec.back() + 1)) * height[idx];
                }
                if (ones > maxOnes) {
                    maxOnes = ones;
                }
            }
            if (vec.empty() || height[vec.back()] < height[j]) {
                vec.push_back(j);
            }
            else {
                vec.back() = j;
            }
        }
        while (!vec.empty()) {
            idx = vec.back();
            vec.pop_back();
            if (vec.empty()) {
                ones = m * height[idx];
            }
            else {
                ones = (m - (vec.back() + 1)) * height[idx];
            }
            if (ones > maxOnes) {
                maxOnes = ones;
            }
        }
    }
    cout << maxOnes << endl;
    return 0;
}