// 연결리스트로 큐 작성하기
#include <stdio.h>
#include <stdlib.h>
/*
    자료구조: data와 *next
*/

//구조체 정의
struct _node
{
    int key;
    struct _node *next;
} node_t;

typedef struct _node node_t;

// 초기화
node_t *head = NULL, *tail = NULL;

// insert func
void insert_node(int n){
    // 새로운 노드를 동적할당해서 생성
    node_t *new_node = (node_t *) malloc(sizeof(node_t));

    // 값 입력
    new_node->key = n;
    new_node->next = NULL;

    
    if (head == NULL)
    {
        // 처음 값을 입력
        head = new_node;
        tail = new_node;
    
    } else {
        // 아니라면,
        tail->next = new_node;
        tail = new_node;
    }
}

int delete_node(){
    // 지울 노드 
    node_t *node;
    int r;

    if (head == NULL)
    {   
        // 지울 노드가 없음.
        return -1;
    }

    node = head;
    head = head->next;

    // 모두 다 지웠다면,
    if (head == NULL)
    {
        tail = NULL;
    }
    
    r = node->key;
    free(node);
    return r;
}

int main(){

    int number, r;

    do {
        printf("input number: ");
        scanf("%d", &number);

        if (number > 0)
        {
            insert_node(number);
        } else if (number == 0){
            r = delete_node();
            printf("[%d]\n", r);
        }
    } while (number >= 0);

    return 0;
}