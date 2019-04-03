#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int id;
    struct _Node* next;
} Node;

Node* Node_new(int id) {
  Node* n =  malloc(sizeof(Node));
  n->id = id;
  n->next = NULL;
  return n;
}

void List_push(Node** lst, Node* n) {
  if (*lst) {
    List_push( &((*lst)->next), n);
  } else {
    *lst = n;
  }
}

void List_print(Node** lst) {
  if (*lst) {
    printf("%d\n", (*lst)->id);
    List_print(&((*lst)->next));
  }
}

void main () {
  Node* n0 = Node_new(0);
  Node* n1 = Node_new(1);
  Node* n2 = Node_new(2);

  Node* list = NULL;


  List_push(&list, n0);
  List_push(&list, n1);
  List_push(&list, n2);

  List_print(&list);

}