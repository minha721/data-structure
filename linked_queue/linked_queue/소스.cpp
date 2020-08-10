#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int element; //����� Ÿ��
typedef struct QueueNode { //ť�� ����� Ÿ��
	element item;
	struct QueueNode *link;
} QueueNode;
typedef struct { //ť ADT ����
	QueueNode *front, *rear;
} QueueType;

//���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ �Լ�
void init(QueueType *q)
{
	q->front = q->rear = 0;
}

//���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == NULL);
}

//��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return 0;
	//�޸� �Ҵ� �������� ������ ���� �ʴ� �� ��ȭ���´� �����Ƿ� �׻� 0 ��ȯ
}

//���� �Լ�
void enqueue(QueueType *q, element item)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error((char*)"�޸𸮸� �Ҵ��� �� �����ϴ�.");
	else {
		temp->item = item; //������ ����
		temp->link = NULL; //��ũ �ʵ带 NULL
		if (is_empty(q)) { //ť�� �����̸�
			q->front = temp;
			q->rear = temp;
		}
		else { //ť�� ������ �ƴ϶��
			q->rear->link = temp; //���� �߿�
			q->rear = temp;
		}
	}
}

//���� �Լ�
element dequeue(QueueType *q)
{
	QueueNode *temp = q->front;
	element item;
	if (is_empty(q)) //���� ����
		error((char*)"ť�� ����ֽ��ϴ�.");
	else {
		item = temp->item; //�����͸� ������
		q->front = q->front->link; //front�� ������带 ����Ű���� �Ѵ�.
		if (q->front == NULL) //���� ����
			q->rear = NULL;
		free(temp); //�����޸� ����
		return item; //������ ��ȯ
	}
}

//peek �Լ�
element peek(QueueType *q)
{
	element item;
	if (is_empty(q))
		error((char*)"ť�� ����ֽ��ϴ�.");
	else {
		item = q->front->item; //�����͸� ������
		return item;
	}
}

int main()
{
	QueueType q;

	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));

	return 0;
}