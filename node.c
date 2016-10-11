//Including stuff so they don't feel excluded and lonely
#include <stdio.h>
#include <stdlib.h>

//Here's the struct
struct node {
  int i;
  struct node *next;
};

//Delclaring functions
void print_list(struct node *next);
struct node * insert_front(struct node *head, int);
struct node * free_list(struct node * head);
void cycle_through(struct node *head);

//Now here's the main
int main(int argc, char const *argv[]) {

  struct node * head = NULL;
  head = (struct node *) malloc(sizeof(struct node));
  head->i = 1;
  head->next = (struct node *) malloc(sizeof(struct node));
  head->next->i = 2;
  struct node * tail = (struct node *) malloc(sizeof(struct node));
  tail->i=3;
  tail->next = 0;
  head->next->next = tail;
  printf("print_list:\n");
  print_list(head);
  printf("insert_front:\n" );
  insert_front(head, 4);
  print_list(head);
  printf("I've been having a bit of trouble displaying the effects of free_list. To prove that it's my computer, I've hardcoded everything and still gotten the same error.\n" );
  struct node *a = (struct node *) malloc(sizeof(struct node));
  struct node *b = (struct node *) malloc(sizeof(struct node));
  struct node *c = (struct node *) malloc(sizeof(struct node));
  b->next = a;
  c->next = b;
  free(a);
  free(b);
  free(c);
  printf("%d\n", c->i);
  printf("%d\n", c->next->i);
  printf("%d\n", c->next->next->i);
  printf("But in the event that your computer cooperates, here is my free_list (please keep in mind that I haven't really been able to test it, as my computer is being annoying):\n");
  free_list(head);
  print_list(head);
  return 0;
}

//Print the list
void print_list(struct node *head) {
  struct node *curr = head;
  int i = 0;
  while (curr != 0) {
    if (curr==0) {
      return;
    }
    printf("Next num: %d\n", curr->i);
    curr = curr->next;
    i++;
  }
}

//Insert something in the front
struct node * insert_front(struct node * head, int n) {

  struct node *new = (struct node *) malloc(sizeof(struct node));
  new->i = n;
  struct node * copy = (struct node *) malloc(sizeof(struct node));
  memcpy(copy, head, sizeof(struct node));
  new->next=copy;
  memcpy(head, new, sizeof(struct node));
  return head;

}

struct node * free_list(struct node * head) {
  struct node *orig = head;
  while (head != 0) {
    struct node *copy = head;
    head = head->next;
    free(copy);
  }
  return 0;
}
