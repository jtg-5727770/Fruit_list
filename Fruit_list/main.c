#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
} element;
typedef struct ListNode { 
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* delet(ListNode* head, element x)
{
	if (head == NULL) {
		error("����Ʈ�� ����ֽ��ϴ�.");
		return NULL;
	}

	ListNode* p = head;
	ListNode* prev = NULL;

	while (p != NULL) {
		if (strcmp(p->data.name, x.name) == 0)
			break;
		prev = p;
		p = p->link;
	}

	if (prev == NULL)
		head = head->link;
	else
		prev->link = p->link;

	free(p);
	return head;
}

ListNode* search_list(ListNode* head, element x)
{
	ListNode* p = head;
	while (p != NULL) {
		if (strcmp(p->data.name, x.name) == 0)
			return p;
		p = p->link;
	}
	return NULL;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}

int main(void) {
	ListNode* head = NULL;
	ListNode* head2 = NULL;
	element data;
	int n;
	char fruit[100];

	strcpy_s(data.name, sizeof(data.name), "Mango");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(data.name), "Orange");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(data.name), "Apple");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(data.name), "Grape");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(data.name), "Cherry");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(data.name), "Plum");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(data.name), "Guava");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(data.name), "Raspberry");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(data.name), "Banana");
	head = insert_first(head, data);
	strcpy_s(data.name, sizeof(data.name), "Peach");
	head = insert_first(head, data);

	while (1) {

		printf("=========�޴�=========\n");
		printf("1.����Ʈ�� ���ο� ������ �߰�\n");
		printf("2.����Ʈ�� �մ� ������ ����\n");
		printf("3.������ ���� ����� ���\n");
		printf("4.����\n");
		printf("��ȣ�� �����ϼ���: ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			printf("�߰��� ������ �Է��ϼ���: ");
			scanf_s("%s", fruit, 100);
			fruit[sizeof(fruit) - 1] = '\0';
			element newfruit;
			strcpy_s(newfruit.name, sizeof(newfruit.name), fruit);

			if (search_list(head, newfruit) != NULL) {
				printf("�̹� ����Ʈ�� �����ϴ� �����Դϴ�.\n");
			}
			else {
				head = insert_first(head, newfruit);
				print_list(head);
			}
			break;

		case 2:
			printf("������ ������ �Է��ϼ���: ");
			scanf_s("%s", fruit, 100);
			fruit[sizeof(fruit) - 1] = '\0';;
			element deletfruit;
			strcpy_s(deletfruit.name, sizeof(deletfruit.name), fruit);

			if (search_list(head, deletfruit) == NULL) {
				printf("����Ʈ�� �������� �ʴ� �����Դϴ�.\n");
			}
			else {
				head = delet(head, deletfruit);
				head2 = insert_first(head2, deletfruit);
				print_list(head);
			}
			
			break;
		case 3:
			print_list(head2);
			break;
		case 4:
			printf("���α׷��� �����մϴ�.\n");
			exit(0);
		default:
			printf("�ٽ� �������ּ���.\n");
			while (getchar() != '\n');
		}
	}
	system("pause");
	return 0;
}