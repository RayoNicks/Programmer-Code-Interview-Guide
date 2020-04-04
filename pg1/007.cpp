#include <iostream>
#include <stack>

using namespace std;

int bottomElt(stack<int> &s)
{
    int ret;
    if(s.size() == 1){
        ret = s.top();
        s.pop();
        return ret;
    }
    int top = s.top();
    s.pop();
    ret = bottomElt(s);
    s.push(top);
    return ret;
}

void reverseStack(stack<int> &s)
{
    int bot;
    if(!s.empty()){
        bot = bottomElt(s);
        reverseStack(s);
        s.push(bot);
    }
}

int main()
{
    int N, num;
    cin >> N;
    stack<int> s;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        s.push(num);
    }
    reverseStack(s);
    while(!s.empty()){
        cout << bottomElt(s) << ' ';
    }
    return 0;
}