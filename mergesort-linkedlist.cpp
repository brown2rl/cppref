#include <iostream>

struct Node {
    int value;
    Node* next;
};

Node* mergeSortedLists(Node* left, Node* right) {
    Node dummy{0, nullptr};
    Node* tail = &dummy;

    while (left != nullptr && right != nullptr) {
        if (left->value <= right->value) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = left != nullptr ? left : right;
    return dummy.next;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* right = slow->next;
    slow->next = nullptr;

    Node* leftSorted = mergeSort(head);
    Node* rightSorted = mergeSort(right);
    return mergeSortedLists(leftSorted, rightSorted);
}

void printList(const Node* head) {
    for (const Node* current = head; current != nullptr; current = current->next) {
        std::cout << current->value;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
    }
    std::cout << '\n';
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    const int values[] = {38, 27, 43, 3, 9, 82, 10};
    
    Node* head = head;
    Node** tail = &head;

    for (int value : values) {
        *tail = new Node{value, nullptr};
        tail = &((*tail)->next);
    }

    std::cout << "Original list: ";
    printList(head);

    head = mergeSort(head);

    std::cout << "Sorted list:   ";
    printList(head);

    deleteList(head);
    return 0;
}
