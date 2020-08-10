#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int element; //요소의 타입
typedef struct DlistNode { //노드의 타입
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
}DlistNode;
typedef struct DequeType { //덱의 타입
	DlistNode *head;
	DlistNode *tail;
} DequeType;

//오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화 함수
void init(DequeType *dq)
{
	dq->head = dq->tail = NULL;
}

DlistNode *create_node(DlistNode *llink, element item, DlistNode *rlink)
{
	DlistNode *node = (DlistNode*)malloc(sizeof(DlistNode));
	if (node == NULL)error((char*)"메모리 할당 오류");
	node->llink = llink;
	node->data = item;
	node->rlink = rlink;
	return node;
}

int is_empty(DequeType *dq)
{
	if (dq->head == NULL) return TRUE;
	else return FALSE;
}

void add_rear(DequeType *dq, element item)
{
	DlistNode *new_node = create_node(dq->tail, item, NULL);
	if (is_empty(dq))
		dq->head = new_node;
	else
		dq->tail->rlink = new_node;
	dq->tail = new_node;
}

void add_front(DequeType *dq, element item)
{
	DlistNode *new_node = create_node(NULL, item, dq->head);

	if (is_empty(dq))
		dq->tail = new_node;
	else
		dq->head->llink = new_node;
	dq->head = new_node;
}

element delete_front(DequeType *dq)
{
	element item;
	DlistNode *removed_node;

	if (is_empty(dq))
		error((char*)"공백 덱에서 삭제");
	else {
		removed_node = dq->head; //삭제할 노드
		item = removed_node->data; //데이터 추출
		dq->head = dq->head->rlink; //헤드 포인터 변경
		free(removed_node); //메모리 공간 반납
		if (dq->head == NULL) //공백상태이면
			dq->tail = NULL;
		else //공백상태가 아니면
			dq->head->llink = NULL;
	}
	return item;
}

//후단에서의 삭제
element delete_rear(DequeType *dq)
{
	element item;
	DlistNode *removed_node;

	if (is_empty(dq)) error((char*)"공백 덱에서의 삭제");
	else {
		removed_node = dq->tail; //삭제할 노드
		item = removed_node->data; //데이터 추출
		dq->tail = dq->tail->llink; //테일 포인터 변경
		free(removed_node); //메모리 공간 반납

		if (dq->tail == NULL) //공백상태이면
			dq->head = NULL;
		else //공백상태가 아니면
			dq->tail->rlink = NULL;
	}
	return item;
}

void display(DequeType *dq)
{
	DlistNode *p;
	printf("(");
	for (p = dq->head; p != NULL; p = p->rlink) {
		printf("%d ", p->data);
	}
	printf(")\n");
}

int main()
{
	DequeType deque;

	init(&deque);
	add_front(&deque, 10);
	add_front(&deque, 20);
	add_rear(&deque, 30);
	display(&deque);

	delete_front(&deque);
	delete_rear(&deque);
	display(&deque);

	return 0;
}
