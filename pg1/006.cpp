#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Queue
{
private:
    stack<int> enque;
    stack<int> deque;
    void moveElt()
    {
        if(deque.empty()){
            while(!enque.empty()){
                deque.push(enque.top());
                enque.pop();
            }
        }
    }
public:
    void add(int x)
    {
        enque.push(x);
    }
    void poll()
    {
        moveElt();
        deque.pop();
    }
    int peek()
    {
        moveElt();
        return deque.top();
    }
};

int main()
{
    Queue queue;
    int N, num;
    cin >> N;
    string strOp;
    for(int i = 0; i < N; i++)
    {
        cin >> strOp;
        if(strOp == "add"){
            cin >> num;
            queue.add(num);
        }
        else if(strOp == "peek"){
            cout << queue.peek() << endl;
        }
        else if(strOp == "poll"){
            queue.poll();
        }
        else;
    }
    return 0;
}