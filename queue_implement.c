#include <stdio.h>
#define Q_SIZE 5

typedef struct {
    int data[Q_SIZE + 1];
    int head, tail;
} Queue;

void enqueue(Queue *q, int item){
    
    if ((q->tail + 1) % (Q_SIZE + 1) == q->head) {
        printf("Queue is full!\n");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (Q_SIZE + 1);
}

int dequeue(Queue *q){
    
    if (q->tail == q->head) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->data[q->head];
    q->head = (q->head + 1) % (Q_SIZE + 1);
    return item;
    
}

int main(int argc, const char * argv[]) {
    
    Queue q;
    int item;
    
    //initially head and tail 0
    q.head = 0;
    q.tail = 0;
    
    //Enqueue operation
    enqueue(&q, 1);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 2);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 3);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 4);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 5);
    printf("tail = %d\n", q.tail);
    enqueue(&q, 6);
    printf("tail = %d\n", q.tail);
    
    
    //Dequeue operation
    printf("Begining head = %d\n", q.head);
    item = dequeue(&q);
    printf("item = %d, head = %d\n", item, q.head);
    item = dequeue(&q);
    printf("item = %d, head = %d\n", item, q.head);
    item = dequeue(&q);
    printf("item = %d, head = %d\n", item, q.head);
    item = dequeue(&q);
    printf("item = %d, head = %d\n", item, q.head);
    item = dequeue(&q);
    printf("item = %d, head = %d\n", item, q.head);
   
    
    return 0;
}
