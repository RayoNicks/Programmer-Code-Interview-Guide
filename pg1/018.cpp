#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int n, num;
    cin >> n >> num;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    deque<int> dqMax, dqMin;
    int begin = 0, end = 0, cnt = 0;
    while (begin != n) {
        while (end != n) {
            while (!dqMax.empty() && vec[end] >= vec[dqMax.back()]) {
                dqMax.pop_back();
            }
            dqMax.push_back(end);
            while (!dqMin.empty() && vec[end] <= vec[dqMin.back()]) {
                dqMin.pop_back();
            }
            dqMin.push_back(end);
            if (vec[dqMax.front()] - vec[dqMin.front()] > num) {
                break;
            }
            end++;
        }
        cnt += end - begin;
        begin++;
        if (begin > dqMax.front()) {
            dqMax.pop_front();
        }
        if (begin > dqMin.front()) {
            dqMin.pop_front();
        }
    }
    cout << cnt << endl;
    return 0;
}