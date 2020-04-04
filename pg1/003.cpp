#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int begin = 0, end = n;
    while(begin < end - 1){
        if(vec[begin] + vec[end - 1] > k){
            end--;
        }
        else if(vec[begin] + vec[end - 1] < k){
            begin++;
        }
        else{
            cout << vec[begin] << ' ' << vec[end - 1] << endl;
            int tmp = vec[begin];
            while(begin < end - 1 && vec[begin] == tmp) begin++;
        }
    }
    return 0;
}