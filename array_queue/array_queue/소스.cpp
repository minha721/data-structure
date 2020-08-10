#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화 함수
void init(QueueType *q)
{
	q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error((char*)"큐가 포화상태입니다.\n");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error((char*)"큐가 공백상태입니다.\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

//삭제 함수
element peek(QueueType *q)
{
	if (is_empty(q))
		error((char*)"큐가 공백상태입니다.\n");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main()
{
	QueueType q;
	init(&q);
	printf("front=%d, rear=%d\n", q.front, q.rear);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("front=%d, rear=%d\n", q.front, q.rear);

	return 0;
}