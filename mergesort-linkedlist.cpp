#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* next;
    Node* previous;
};

std::vector<int> mergeSortedLists(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> merged;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            merged.push_back(left[i]);
            i++;
        } else {
            merged.push_back(right[j]);
            j++;
        }
    }

    // Append any remaining elements from either list
    while (i < left.size()) {
        merged.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        merged.push_back(right[j]);
        j++;
    }

    return merged;
}

std::vector<int> mergeSort(const std::vector<int>& values) {

    if (values.size() <= 1) {
        return values;
    }

    const auto midpoint = values.begin() + values.size() / 2;

    const std::vector<int> left(values.begin(), midpoint);
    const std::vector<int> right(midpoint, values.end());

    const std::vector<int> leftSorted = mergeSort(left);
    const std::vector<int> rightSorted = mergeSort(right);

    return mergeSortedLists(leftSorted, rightSorted);
}

void printListForward(const Node* head, int numberOfNodes) {
    for (int i = 0; i < numberOfNodes; i++) {
        std::cout << head->value;
        if (head != nullptr) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << '\n';
}

void printListBackward(const Node* tail, int numberOfNodes) {    
    for (int i = 0; i < numberOfNodes; i++) {
        std::cout << tail->value;
        if (tail->previous != nullptr) {
            std::cout << " <- ";
        }
        tail = tail->previous;
    }
    std::cout << '\n';
}

int deleteList(Node* tail, int& numberOfNodes) {
    
    while (numberOfNodes > 0) {
        Node* prev = tail->previous;
        delete tail;
        tail = prev;
        numberOfNodes--;
    }
    return numberOfNodes;
}

bool createNodes(Node*& head, Node*& tail, const std::vector<int>& values, int& numberOfNodes) {
    for (int i = 0; i < values.size(); i++) {
        if (i == 0){
            // initialize the head and tail of the list (1 node)
            head = new Node{values[i], nullptr, nullptr};
            tail = head;
        } else if (i == 1){
            // update head next and previous pointers to create a 2-node list
            tail = new Node{values[i], head, head};
            head->previous = tail;
            head->next = tail;
        } else {
            // update tail next and previous pointers to add a new node to the end of the list
            Node* newNode = new Node{values[i], head, tail};
            tail->next = newNode;
            tail = newNode;
            head->previous = tail;
        }
        numberOfNodes++;
    }
    std::cout << "Number of nodes created: " << numberOfNodes << "\n";
    
    return true;
}

int main() {
    std::vector<int> values = {38, 27, 43, 3, 9, 82, 10};
    std::vector<int> &valuesRef = values;

    Node* head = nullptr;
    Node* tail = nullptr;

    int numberOfNodes = 0;

    if (createNodes(head, tail, valuesRef, numberOfNodes)){
    
        std::cout << "Original list: \n";
        printListForward(head, numberOfNodes);

        std::cout << "Reversed list: \n";
        printListBackward(tail, numberOfNodes);
    
        std::cout << "Number of nodes remaining: " << deleteList(tail, numberOfNodes) << "\n";
    }
    if (createNodes(head, tail, mergeSort(valuesRef), numberOfNodes)){
    
        std::cout << "Ascending list: \n";
        printListForward(head, numberOfNodes);

        std::cout << "Descending list: \n";
        printListBackward(tail, numberOfNodes);
    
        std::cout << "Number of nodes remaining: " << deleteList(tail, numberOfNodes) << "\n";
    }

    delete head;
    delete tail;

    return 0;
}
