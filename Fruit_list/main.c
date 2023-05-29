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
		error("리스트가 비어있습니다.");
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

		printf("=========메뉴=========\n");
		printf("1.리스트에 새로운 과일을 추가\n");
		printf("2.리스트에 잇는 과일을 삭제\n");
		printf("3.삭제된 과일 목록을 출력\n");
		printf("4.종료\n");
		printf("번호를 선택하세요: ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			printf("추가할 과일을 입력하세요: ");
			scanf_s("%s", fruit, 100);
			fruit[sizeof(fruit) - 1] = '\0';
			element newfruit;
			strcpy_s(newfruit.name, sizeof(newfruit.name), fruit);

			if (search_list(head, newfruit) != NULL) {
				printf("이미 리스트에 존재하는 과일입니다.\n");
			}
			else {
				head = insert_first(head, newfruit);
				print_list(head);
			}
			break;

		case 2:
			printf("삭제할 과일을 입력하세요: ");
			scanf_s("%s", fruit, 100);
			fruit[sizeof(fruit) - 1] = '\0';;
			element deletfruit;
			strcpy_s(deletfruit.name, sizeof(deletfruit.name), fruit);

			if (search_list(head, deletfruit) == NULL) {
				printf("리스트에 존재하지 않는 과일입니다.\n");
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
			printf("프로그램을 종료합니다.\n");
			exit(0);
		default:
			printf("다시 선택해주세요.\n");
			while (getchar() != '\n');
		}
	}
	system("pause");
	return 0;
}