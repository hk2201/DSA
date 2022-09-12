#include <iostream>
#include <queue>
using namespace std;
int main()
{

    // max heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "As in max heap the root node has the largest value so " << pq.top() << endl;
    pq.pop();
    cout << "As in max heap the root node has the largest value so " << pq.top() << endl;

    // min heap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << minheap.top();

    return 0;
}