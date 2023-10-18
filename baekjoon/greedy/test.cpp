// 백준 1260. DFS와 BFS 23.06.28
#include <iostream>
using namespace std;
#include <deque>

deque<int> queue;

int main() {

    cout << queue.empty() << endl;
    queue.push_back(7);
    queue.push_back(8);

    
    auto it = queue.begin();
    for (;it<queue.end(); it++)
        cout << *it << ' ';
    cout << endl;
    return 0;
}