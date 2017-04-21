#include <iostream>
#include <vector>

using namespace std;

// Priority Queue
vector<int> priorityqueue {-65536, 12, 7, 8, 4, 6, 5, 3 ,1};

// 
void enQueue(const int &x){
	priorityqueue.push_back(x);
	int hole = priorityqueue.size() - 1;
	for(; hole > 1 && x > priorityqueue[hole/2]; hole /= 2){
		priorityqueue[hole] = priorityqueue[hole/2];
	}
	priorityqueue[hole] = x;
}


void percolateDown(int hole){
	// Your codes here.
}

int deQueue(){
    int minItem = priorityqueue[1];
    priorityqueue[1] = priorityqueue[priorityqueue.size() - 1];
    priorityqueue.pop_back();
    percolateDown(1);
    return minItem;
}


void printQueue(){
	cout << "Current Priority Queue is: ";
	for(auto i = priorityqueue.begin() + 1; i != priorityqueue.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;
}
int main() {
	enQueue(13);
	enQueue(-1);
	enQueue(10);
	enQueue(15);
	printQueue();
	while(priorityqueue.size() != 1){
		cout << deQueue() << " Pop from Priority Queue" << endl;
	}
	return 0;	
}
