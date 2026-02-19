// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool



MyCircularQueue* myCircularQueueCreate(int k) 
{
    // TODO:
    // filter invalid input
    if (k <= 0)
    {
        return NULL;
    }

    // - Allocate MyCircularQueue
    MyCircularQueue* queue = malloc(sizeof(MyCircularQueue));
    if (!queue)
    {
        return NULL;
    }

    // - Allocate the internal buffer `data` of length k
    queue->data = malloc(sizeof(int) * k);

  //  if (!queue->data) 
    //{
      //  free(queue);
       // return NULL;
   // }

  
    // - Initialize capacity, head, tail, size
    queue->capacity = k;
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;

    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* queue, int value) 
{
    // TODO:
    // - If full, return false
    if (!queue || queue->size >= queue->capacity)
    {
        return false;
    }

    // - Write value at tail, advance tail (wrap), size++
    queue->data[queue->tail] = value;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;

    return true;
}




bool myCircularQueueDeQueue(MyCircularQueue* queue) 
{
    // TODO:
    // - If empty, return false
    if (!queue || queue->size <= 0)
    {
        return false;
    }
    // - Advance head (wrap), size--
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;

    return true;
}

int myCircularQueueFront(MyCircularQueue* queue) 
{
    // TODO:
    // - Return -1 if empty
    // - Otherwise return data[head]
    if (!queue || queue->size <= 0)
    {
        return -1;
    }
    return queue->data[queue->head];
}

int myCircularQueueRear(MyCircularQueue* queue) 
{
    // TODO:
    // - Return -1 if empty
    if (!queue || queue->size <= 0)
    {
        return -1;
    }
    // - Otherwise return the last inserted element
    //   (tail points to next insertion position)
    int index = (queue->tail - 1 + queue->capacity) % queue->capacity;
    return queue->data[index];
}




bool myCircularQueueIsEmpty(MyCircularQueue* queue) 
{
    // TODO:
    // - Return true if size == 0
    if (!queue || queue->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool myCircularQueueIsFull(MyCircularQueue* queue) 
{
    // TODO:
    // - Return true if size == capacity
    if (!queue)
    {
        return false;
    }
    if (queue->size == queue->capacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void myCircularQueueFree(MyCircularQueue* queue) 
{
    // TODO:
    // - Free internal buffer then free queue
    if (!queue)
    {
        return;
    }
    free(queue->data);
    free(queue);
}



