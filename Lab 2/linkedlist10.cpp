#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

int countCriticalPoints(Node* head) {
    if (!head || !head->next || !head->next->next)
        return 0;

    int count = 0;
    Node* current = head->next;

    while (current->next && current->next->next) {
        if ((current->data < current->next->data && current->data < current->next->next->data) ||
            (current->data > current->next->data && current->data > current->next->next->data)) {
            count++;
        }
        current = current->next;
    }
    return count;
}

Node* createLinkedList(int arr[], int size) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr1[] = {1, 2, 3, 3, 3, 5, 1, 3, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    Node* head1 = createLinkedList(arr1, size1);
    cout << "Critical points: " << countCriticalPoints(head1) << endl;

    int arr2[] = {1, 2, 3, 2, 1, 3, 2, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    Node* head2 = createLinkedList(arr2, size2);
    cout << "Critical points: " << countCriticalPoints(head2) << endl;

    return 0;
}
