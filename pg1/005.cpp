#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> stk;
    stack<int> min;
public:
    void push(int elt)
    {
        stk.push(elt);
        if(min.empty() || min.top() > elt){
            min.push(elt);
        }
        else{
            min.push(min.top());
        }
    }
    void pop()
    {
        stk.pop();
        min.pop();
    }
    int Min()
    {
        return min.top();
    }
};

int main()
{
    int N, num;
    cin >> N;
    string strOp;
    MinStack ms;
    for(int i = 0; i < N; i++)
    {
        cin >> strOp;
        if(strOp == "push"){
            cin >> num;
            ms.push(num);
        }
        else if(strOp == "pop") ms.pop();
        else if(strOp == "getMin") cout << ms.Min() << endl;
        else;
    }
    return 0;
}