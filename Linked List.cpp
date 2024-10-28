// C++ code to Clone a linked list with next and random
// pointer using Hashing 

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;
  
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};

// Function to clone the linked list
Node* cloneLinkedList(Node* head) {
  
    // Map to store new nodes corresponding to
      // their original nodes
    unordered_map<Node*, Node*> mp;
    Node *curr = head;
  
    // Traverse original linked list to store new 
      // nodes corresponding to original linked list
    while (curr != NULL) {
        mp[curr] = new Node(curr->data);
        curr = curr->next;
    }
    
      curr = head;
      
    // Loop to update the next and random pointers 
      // of new nodes 
    while (curr != NULL) {
        
          // Update the next pointer of new node
          mp[curr]->next = mp[curr->next];
      
          // Update the random pointer of new node
          mp[curr]->random = mp[curr->random];
      
          curr = curr->next;
    }
  
    // Return the head of the clone
    return mp[head];
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << "(";
          if(head->random)
              cout << head->random->data << ")";
          else 
              cout << "null" << ")";
        
          if(head->next != NULL)
              cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
  
    // Creating a linked list with random pointer
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;
  
    // Print the original list
    cout << "Original linked list:\n";
    printList(head);
  
    // Function call
    Node* clonedList = cloneLinkedList(head);
  
    cout << "Cloned linked list:\n";
    printList(clonedList);
  
    return 0;
}
