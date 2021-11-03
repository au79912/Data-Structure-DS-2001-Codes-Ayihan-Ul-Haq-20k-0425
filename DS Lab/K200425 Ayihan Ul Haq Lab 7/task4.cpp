#include <iostream>

using namespace std;
  
// A structure to represent a queue
class Queue {
public:
    int front, rear, size;
    unsigned capacity;
    int* array;
};
  
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
Queue* createQueue(unsigned capacity)
{
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
  
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = new int[queue->capacity];
    return queue;
}

void ADDQueue(Queue* queue, int item)
{
    if (QueueCapacity(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}

int RemoveQueue(Queue* queue)
{
    if (QueueCapacity(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int QueueCapacity(Queue* queue)
{
    return (queue->size == queue->capacity);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}