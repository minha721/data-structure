#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <limits.h>

#define FALSE 0
#define TRUE 1

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;
typedef struct {
	ListNode *head; //헤드 포인터
	int length; //노드의 개수
}LinkedListType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//phead : 리스트의 헤드 포인터의 포인터
//p : 선행 노드
//new_node : 삽입될 노드
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
	if (*phead == NULL) { //공백리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { //p가 NULL이면 첫번째 노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	}
	else { //p 다음에 삽입
		new_node->link = p->link;
		p->link = new_node;
	}
}

//phead : 헤드 포인터에 대한 포인터
//p : 삭제될 노드의 선행 노드
//removed : 삭제될 노드
void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

//리스트 안에서 pos 위치의 노드를 반환한다.
ListNode *get_node_at(LinkedListType *list, int pos)
{
	int i;
	ListNode *tmp_node = list->head;
	if (pos < 0) return NULL;
	for (i = 0; i < pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;
}

//리스트의 항목의 개수를 반환한다.
int get_length(LinkedListType *list)
{
	return list->length;
}

//주어진 위치에 데이터를 삽입한다.
void add(LinkedListType *list, int position, element data)
{
	ListNode *p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
		if (node == NULL) error((char *)"메모리 할당에러");
		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node((&list->head), p, node);
		list->length++;
	}
}

//리스트의 끝에 데이터를 삽입한다.
void add_last(LinkedListType *list, element data)
{
	add(list, get_length(list), data);
}

//리스트의 처음부분에 데이터를 삽입한다.
void add_first(LinkedListType *list, element data)
{
	add(list, 0, data);
}

int is_empty(LinkedListType *list)
{
	if (list->head == NULL) return 1;
	else return 0;
}

//주어진 위치의 데이터를 삭제한다.
void delete_data(LinkedListType *list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		ListNode *p = get_node_at(list, pos - 1);
		remove_node(&(list->head), p, (p != NULL) ? p->link : NULL);
		list->length--;
	}
}

element get_entry(LinkedListType *list, int pos)
{
	ListNode *p;
	if (pos >= list->length) error((char *)"위치 오류");
	p = get_node_at(list, pos);
	return p->data;
}

void clear(LinkedListType *list)
{
	int i;
	for (i = 0; i < list->length; i++)
		delete_data(list, i);
}

//버퍼의 내용을 출력한다.
void display(LinkedListType *list)
{
	int i;
	ListNode *node = list->head;
	printf("( ");
	for (i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}
	printf(" )\n");
}

//데이터의 값이 s인 노드를 찾는다.
int is_in_list(LinkedListType *list, element item)
{
	ListNode *p;
	p = list->head; //헤드 포인터에서부터 시작한다.
	while ((p != NULL)) {
		//노드의 데이터가 item이면
		if (p->data == item)
			break;
		p = p->link;
	}
	if (p == NULL) return FALSE;
	else return TRUE;
}

//리스트를 초기화한다.
void init(LinkedListType *list)
{
	if (list == NULL) return;
	list->length = 0;
	list->head = NULL;
}

int main()
{
	LinkedListType list1;

	init(&list1);
	add(&list1, 0, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);

	//list1=(10,20,30,40)
	display(&list1);

	//list1=(10,20,30)
	delete_data(&list1, 3);
	display(&list1);

	//list1=(20,30)
	delete_data(&list1, 0);
	display(&list1);

	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "성공" : "실패");
	printf("%d\n", get_entry(&list1, 0));
}
