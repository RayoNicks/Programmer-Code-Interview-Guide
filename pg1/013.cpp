#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N, elt;
    cin >> N;
    stack<int> sOri, sHelp;
    for(int i = 0; i < N; i++)
    {
        cin >> elt;
        sOri.push(elt);
    }
    int curr, tmp;
    while(!sOri.empty()){
        curr = sOri.top();
        sOri.pop();
        while(!sHelp.empty() && sHelp.top() > curr){
            tmp = sHelp.top();
            sHelp.pop();
            sOri.push(tmp);
        }
        sHelp.push(curr);
    }
    sOri = sHelp;
    while(!sHelp.empty()){
        cout << sHelp.top() << ' ';
        sHelp.pop();
    }
    return 0;
}