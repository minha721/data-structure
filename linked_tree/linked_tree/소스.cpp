#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

//		15
//	4		20
//1		  16  25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

//���� ��ȸ
void inorder(TreeNode *root)
{
	if (root) {
		inorder(root->left); //���ʼ���Ʈ�� ��ȸ
		printf("%d ", root->data); //��� �湮
		inorder(root->right); //�����ʼ���Ʈ�� ��ȸ
	}
}

//���� ��ȸ
void preorder(TreeNode *root)
{
	if (root) {
		printf("%d ", root->data); //��� �湮
		preorder(root->left); //���ʼ���Ʈ�� ��ȸ
		preorder(root->right); //�����ʼ���Ʈ�� ��ȸ
	}
}

//���� ��ȸ
void postorder(TreeNode *root)
{
	if (root) {
		postorder(root->left); //���ʼ���Ʈ�� ��ȸ
		postorder(root->right); //�����ʼ���Ʈ�� ��ȸ
		printf("%d ", root->data); //��� �湮
	}
}

int main()
{
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);

	return 0;
}