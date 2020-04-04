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
    int begin = 0, mid, end, part, tmp;
    while(begin < n - 2){
        mid = begin + 1;
        while(mid < n - 1 && vec[mid] == vec[begin]) mid++;
        end = n;
        part = k - vec[begin];
        while(mid < end - 1){
            if(vec[mid] + vec[end - 1] > part){
                end--;
            }
            else if(vec[mid] + vec[end - 1] < part){
                mid++;
            }
            else{
                cout << vec[begin] << ' ' << vec[mid] << ' ' << vec[end - 1] << endl;
                tmp = vec[mid];
                while(mid < end - 1 && vec[mid] == tmp) mid++;
            }
        }
        tmp = vec[begin];
        while(begin < n - 2 && vec[begin] == tmp) begin++;
    }
}