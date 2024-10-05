// #include <stdio.h>

// #define MAX_SIZE 100001

// typedef struct Node {
//     int data;
//     struct Node *prev;
//     struct Node *next;
// } Node;

// typedef struct {
//     Node *front;
//     Node *rear;
//     int size;
// } Deque;

// Node* create_node(int data) {
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     new_node->data = data;
//     new_node->prev = NULL;
//     new_node->next = NULL;
//     return new_node;
// }

// void push_front(Deque *dequeue, int data){
//     Node *new_node = create_node(data);
//     if (dequeue->size == 0) {
//         dequeue->front = new_node;
//         dequeue->rear = new_node;
//         } else {
//         new_node->next = dequeue->front;
//         dequeue->front->prev = new_node;
//         dequeue->front = new_node;
//     }
//         dequeue->size++;
// }

// void push_back(Deque *dequeue, int data){
//     Node *new_node = create_node(data);
//     if(dequeue->size == 0 ){
//         dequeue->front = new_node;
//         dequeue->rear = new_node;
//     }else{
//         new_node->prev = dequeue->rear;
//         dequeue->rear->next = new_node;
//         dequeue->rear = new_node;
//     }
//      dequeue->size++;
// }

// int pop_front(Deque *dequeue){
//     if (empty(dequeue)) {
//         return -1;
//     }
//     Node *temp = dequeue->front;
//     int data = temp->data;
//     dequeue->front = dequeue->front->next;
//     if (dequeue->front != NULL) {
//         dequeue->front->prev = NULL;
//     } else {
//         dequeue->rear = NULL;
//     }
//     free(temp);
//     dequeue->size--;
//     return data;
// }

// int pop_back(Deque *dequeue){
//       if (deque->size == 0) {
//         return -1;
//     }
//     Node *temp = deque->rear;
//     int data = temp->data;
//     deque->rear = deque->rear->prev;
//     if (deque->rear != NULL) {
//         deque->rear->next = NULL;
//     } else {
//         deque->front = NULL;
//     }
//     free(temp);
//     deque->size--;
//     return data;
// }


// int size(Deque *deque) {
//     return deque->size;
// }

// int empty(Deque *deque) {
//     return deque->size == 0;
// }

// int back(Deque *deque) {
//     if (deque->size == 0) {
//         return -1;
//     }
//     return deque->rear->data;
// }


// // 초기화 함수
// void init(Deque *deque) {
//     deque->front = NULL;
//     deque->rear = NULL;
//     deque->size = 0;
// }


// int main(){
//      Deque dequeq;
//     init(&dequeq);

//     int n, data;
//     char command[10];

//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         scanf("%s", command);

//         if (strcmp(command, "push_front") == 0) {
//             scanf("%d", &data);
//             push_front(&dequeq, data);
//         }else if (strcmp(command, "push_back") == 0) {
//             scanf("%d", &data);
//             push_back(&dequeq,data);
//         }else if (strcmp(command, "pop_front") == 0) {
//             printf("%d\n", pop_front(&dequeq));
//         } else if (strcmp(command, "pop_back") == 0) {
//             printf("%d\n", pop_back(&dequeq));
//         } else if (strcmp(command, "empty") == 0) {
//             printf("%d\n", empty(&dequeq));
//         } else if (strcmp(command, "size") == 0) {
//             printf("%d\n", size(&dequeq));
//         } else if (strcmp(command, "front") == 0) {
//             printf("%d\n", front(&dequeq));
//         } else if (strcmp(command, "back") == 0) {
//             printf("%d\n", back(&dequeq));
//         }
//     }
//     return 0;
// }