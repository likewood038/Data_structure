#include <stdio.h>
#include <stdlib.h>

#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)
	
#define list_for_each_prev(pos, head) \
	for  (pos = (head); pos->next != (head); pos = pos->next)

#define LIST_HEAD(name) \
	struct list_head name = {&(name)}

struct list_head
{
	struct list_head *next;
};

struct node
{
	struct list_head list_head;
	int id;
};

LIST_HEAD(list_head);

void INIT_LIST_HEAD(struct list_head *list){
	list->next = list;
}

void list_add(struct list_head *new, struct list_head *head){
	new->next = head->next;
	head->next = new;
}

void list_del(struct list_head *prev, struct list_head *list){
	prev->next = list->next;
}

void node_add(int id){
	struct node *node = malloc(sizeof(struct node));
	
	node->id = id;
	INIT_LIST_HEAD(&node->list_head);
	
	list_add(&node->list_head, &list_head);
}

void node_del(int id){
	struct list_head *prev;
	
	list_for_each_prev(prev, &list_head)
		if (((struct node *)prev->next)->id == id) list_del(prev, prev->next);
}

void node_show(int id){
	struct list_head *pos;
	
	list_for_each(pos, &list_head)
		if (((struct node *)pos)->id == id)
		{
			printf("id = %d\n", id);
			return;
		}
	
	printf("Not found\n");
}

int main()
{
	node_add(1);
	node_add(2);
	node_add(3);
	
	node_del(2);
	
	node_show(1);
	
}
