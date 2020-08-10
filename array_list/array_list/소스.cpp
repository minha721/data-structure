//배열을 이용한 리스트
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	int list[MAX_LIST_SIZE];
	int length;
}ArrayListType;

//오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//리스트 초기화
void init(ArrayListType *L)
{
	L->length = 0;
}

//리스트가 비어 있으면 1반환, 아니면 0반환
int is_empty(ArrayListType *L)
{
	return L->length == 0;
}

//리스트가 가득 차 있으면 1반환, 아니면 0반환
int is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}

//리스트 출력
void display(ArrayListType *L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d\n", L->list[i]);
}

//position 삽입 위치, item 삽입 자료
void add(ArrayListType *L, int position, element item)
{
	if (!is_full(L) && position >= 0 && position <= L->length) {
		for (int i = L->length - 1; i >= position; i--)
			L->list[i + 1] = L->list[i];
		L->list[position] = item;
		L->length++;
	}
}

//position 삭제 위치, 반환 값 삭제 자료
element delete_data(ArrayListType *L, int position)
{
	element item;

	if (position < 0 || position >= L->length)
		error((char *)"위치 오류");
	item = L->list[position];
	for (int i = position; i < (L->length - 1); i++)
		L->list[i] = L->list[i + 1];
	L->length--;
	return item;
}

int main()
{
	ArrayListType list;
	ArrayListType *plist;

	//ListType을 정적으로 생성하고 ListType을 가리키는
	//포인터를 함수의 파라미터로 전달
	init(&list);
	add(&list, 0, 10);
	add(&list, 0, 20);
	add(&list, 0, 30);
	display(&list);

	//ListType을 동적으로 생성하고 ListType을 가리키는
	//포인터를 함수의 파라미터로 전달
	plist = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);
	free(plist);
}