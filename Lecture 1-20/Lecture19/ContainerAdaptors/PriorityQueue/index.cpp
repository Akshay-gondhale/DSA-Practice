// priortiy queue is basically same as normal queue and imported from same package. But here the key difference is
// it stores value as you entered in it but while returning it will give values in ascending or descending orders.

#include <iostream>
#include <queue>
using namespace std;
void printMaxQueue(priority_queue<int> queueData)
{
    int size = queueData.size();
    for (int i = 0; i < size; i++)
    {
        cout << queueData.top() << " ";
        queueData.pop();
    }
    cout << endl;
}
void printMinQueue(priority_queue<int, vector<int>, greater<int>> queueData)
{
    int size = queueData.size();
    for (int i = 0; i < size; i++)
    {
        cout << queueData.top() << " ";
        queueData.pop();
    }
    cout << endl;
}
int main()
{
    // defining defult priority queue in descending order.
    priority_queue<int> maxQueue;
    // pushing elements in random order
    maxQueue.push(3);
    maxQueue.push(0);
    maxQueue.push(2);
    maxQueue.push(1);
    // printing queue. this will print in descending order
    cout << "descending order queue: " << endl;
    printMaxQueue(maxQueue);

    // init ascending order queue
    // here first arg is data type
    // second arg is what it will internally use to store elements. in this we are going with vector
    // third arg is for comparison. It will place newly added element are compared to greatest and placed accordingly
    priority_queue<int, vector<int>, greater<int>> minQueue;
    // pushing elements in random order
    minQueue.push(3);
    minQueue.push(0);
    minQueue.push(2);
    minQueue.push(1);
    // printing queue. this will print in descending order
    cout << "Ascending order queue: " << endl;
    printMinQueue(minQueue);
}