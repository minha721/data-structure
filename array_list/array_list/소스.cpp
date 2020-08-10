//�迭�� �̿��� ����Ʈ
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	int list[MAX_LIST_SIZE];
	int length;
}ArrayListType;

//���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//����Ʈ �ʱ�ȭ
void init(ArrayListType *L)
{
	L->length = 0;
}

//����Ʈ�� ��� ������ 1��ȯ, �ƴϸ� 0��ȯ
int is_empty(ArrayListType *L)
{
	return L->length == 0;
}

//����Ʈ�� ���� �� ������ 1��ȯ, �ƴϸ� 0��ȯ
int is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}

//����Ʈ ���
void display(ArrayListType *L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d\n", L->list[i]);
}

//position ���� ��ġ, item ���� �ڷ�
void add(ArrayListType *L, int position, element item)
{
	if (!is_full(L) && position >= 0 && position <= L->length) {
		for (int i = L->length - 1; i >= position; i--)
			L->list[i + 1] = L->list[i];
		L->list[position] = item;
		L->length++;
	}
}

//position ���� ��ġ, ��ȯ �� ���� �ڷ�
element delete_data(ArrayListType *L, int position)
{
	element item;

	if (position < 0 || position >= L->length)
		error((char *)"��ġ ����");
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

	//ListType�� �������� �����ϰ� ListType�� ����Ű��
	//�����͸� �Լ��� �Ķ���ͷ� ����
	init(&list);
	add(&list, 0, 10);
	add(&list, 0, 20);
	add(&list, 0, 30);
	display(&list);

	//ListType�� �������� �����ϰ� ListType�� ����Ű��
	//�����͸� �Լ��� �Ķ���ͷ� ����
	plist = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);
	free(plist);
}