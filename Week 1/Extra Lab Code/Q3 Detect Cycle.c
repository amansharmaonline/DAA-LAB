#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Detecting cycle
int hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1; // cycle found
    }
    return 0; // no cycle
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Empty list.\n");
        return 0;
    }

    // Creating linked list with random values
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val = rand() % 100; // random 0–99
        struct Node* newNode = createNode(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Randomly decide whether to create a cycle
    int makeCycle = rand() % 2; // 0 or 1
    if (makeCycle) {
        int pos = rand() % n; // cycle start position
        struct Node* temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        tail->next = temp; // create cycle
        printf("Cycle created at node position %d (value=%d)\n", pos, temp->data);
    } else {
        printf("No cycle created.\n");
    }

    // Detect cycle
    if (hasCycle(head))
        printf("Cycle detected!\n");
    else
        printf("No cycle detected.\n");

    return 0;
}
