// Purpose:  To fix the former example's insertion problem at both ends of a
//           linked list.  This code is now error free.
// Author:   Keith Shomper
// Date:     25 Jan 2006

#include <iostream>

using namespace std;

class   Node;

typedef Node* NodePtr;

class   Node {
 public:
   int     key;
   NodePtr next;
};

int main() {
   NodePtr head    = NULL;
   NodePtr prev    = NULL;
   NodePtr curr    = NULL;
   NodePtr newNode = NULL;
   int     val;

   // create and give an intial value to the first Node in the list
   head       = new Node;
   curr       = head;
   curr->key  = 2;
   curr->next = NULL;

   // add another four Nodes to the list
   for (int i = 1; i < 5; i++) {
      curr->next = new Node;
      curr       = curr->next;
      curr->key  = (i+1)*2;
      curr->next = NULL;
   }

   // insert a final Node in the list
   cout << "Please enter a value to insert into the list:  ";
   cin  >> val;

   // find the insertion point
   curr = head;
   while (curr != NULL && curr->key < val) {
      prev = curr;
      curr = curr->next;
   }

   // insert the Node
   newNode       = new Node;
   newNode->key  = val;
   newNode->next = curr;

   if (prev == NULL) {           // inserting at the head of the list
      head = newNode;
   } else {                      // inserting somewhere in the tail of the list
      prev->next = newNode;
   }

   return 0;
}
