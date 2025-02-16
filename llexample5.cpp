// Purpose:  To simplify the former example's insertion code by using a sentinal
//           Node at the beginning of the linked list.
// Author:   Keith Shomper
// Date:     25 Jan 2006

#include <iostream>
#include <cmath>

using namespace std;

class   Node;

typedef Node* NodePtr;
typedef Node* LinkedList;

class   Node {
 public:
   int     key;
   NodePtr next;
};

LinkedList createList() {
   LinkedList l = new Node;
   l->key       = (int) pow(2.0, 31);
   l->next      = NULL;
   return     l;
}

int main() {
   NodePtr head    = createList();
   NodePtr prev    = NULL;
   NodePtr curr    = NULL;
   NodePtr newNode = NULL;
   int     val;

   while (val != 0) {
      cout << "Please enter a value to insert into the list:  ";
      cin  >> val;

      // find the insertion point
      prev = head;
      curr = head->next;
      while (curr != NULL && curr->key < val) {
         prev = curr;
         curr = curr->next;
      }

      // insert the Node
      newNode       = new Node;
      newNode->key  = val;
      newNode->next = curr;
      prev->next    = newNode;

      /*
      if (prev == NULL) {         // inserting at the head of the list
         head = newNode;
      } else {                    // inserting somewhere in the tail of the list
         prev->next = newNode;
      }*/
   }

   return 0;
}
