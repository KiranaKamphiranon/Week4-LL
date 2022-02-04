struct Node {                                      
   int id,score; // each listNode contains a character 
   struct Node *nextPtr;
   struct Node *pPtr; // pointer to next node
}; // end structure listNode                        

typedef struct Node LLnode; // synonym for struct listNode
typedef LLnode* LLPtr; // synonym for ListNode*

// prototypes

int deletes( LLPtr *sPtr, int value);
//int deletes( LLnode **sPtr, int value );

int isEmpty( LLPtr sPtr );
void insert( LLPtr *sPtr, int value , int value2);
//int insert( LLnode **sPtr, int value );

void printList( LLPtr currentPtr );
void printReverse( LLPtr currentPtr );

void instructions( void );


// display program instructions to user
void instructions( void )
{ 
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );
      
} // end function instructions

// insert a new value into the list in sorted order
void insert( LLPtr *sPtr, int value , int value2 )
{ 
   LLPtr newPtr; // pointer to new node
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr; // pointer to current node in list

   newPtr =(LLPtr) malloc( sizeof( LLnode ) ); // create node

   if ( newPtr != NULL ) { // is space available
      newPtr->id = value;
      newPtr->score = value2; // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node
      newPtr->pPtr = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      // loop to find the correct location in the list       
      while ( currentPtr != NULL && value > currentPtr->id ) {
         previousPtr = currentPtr; // walk to ...               
         currentPtr = currentPtr->nextPtr; // ... next node 
      } // end while                                         
      // insert new node at beginning of list
      if ( previousPtr == NULL ) { 
         newPtr->nextPtr = *sPtr;
         if(*sPtr) (*sPtr)->pPtr=newPtr;
         *sPtr = newPtr;
      } // end if
      else if (currentPtr == NULL) {
        previousPtr->nextPtr = newPtr;
        newPtr->pPtr = previousPtr;
      }
      else { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
         
         newPtr->pPtr=previousPtr;
         currentPtr->pPtr=newPtr;
         
      } // end else
   } // end if
   else {
      printf( "%d not inserted. No memory available.\n", value );
   } // end else
} // end function insert

// delete a list element
int deletes( LLPtr *sPtr, int value)
{ 
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr; // pointer to current node in list
   LLPtr tempPtr; // temporary node pointer

   // delete first node
   if ( value == ( *sPtr )->id ) { 
      if ((*sPtr)->nextPtr != NULL){
      tempPtr = (*sPtr); // hold onto node being removed
      *sPtr = ( *sPtr )->nextPtr; // de-thread the node
      (*sPtr)->pPtr = NULL;
      free( tempPtr ); // free the de-threaded node
      return value;
      } 
      else if ((*sPtr)->nextPtr == NULL){
        (*sPtr)=NULL;
        return value;
      }
   } // end if
   else if (( *sPtr )->nextPtr != NULL )  { 
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;
      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->id != value ) { 
         previousPtr = currentPtr; // walk to ...  
         currentPtr = currentPtr->nextPtr; // ... next node  
      } // end while
      if (currentPtr != NULL){
      // delete node at currentPtr
        if ( currentPtr->nextPtr == NULL) { 
         tempPtr = currentPtr;
         currentPtr->pPtr = previousPtr;
         previousPtr->nextPtr = NULL;
         free( tempPtr );
         return value;
       }
        else{ 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         previousPtr->nextPtr->pPtr = previousPtr;
         free( tempPtr );
         return value;
        } // end if
      }
   } // end else
   return value-1;
} // end function delete

// return 1 if the list is empty, 0 otherwise
int isEmpty( LLPtr sPtr )
{ 
   return sPtr == NULL;
} // end function isEmpty

// print the list
void printList( LLPtr currentPtr )
{ 
   // if list is empty
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } // end if
   else { 
      puts( "-----------------------------\nThe list is:" );

      // while not the end of the list
      while ( currentPtr != NULL ) { 
         printf( "ID: %-7d Score: %d\n", currentPtr->id,currentPtr->score );
         currentPtr = currentPtr->nextPtr;   
      } // end while

      puts( "NULL\n-----------------------------\nThe reverse is:");
   } // end else
} // end function printList

void reverseLLPrint( LLPtr currentPtr ) {
  if ( isEmpty( currentPtr ) ) {} 
  else {
    while ( currentPtr->nextPtr != NULL ) { 
         currentPtr = currentPtr->nextPtr;   
    }
    while (currentPtr != NULL) {
        printf("ID: %-7d Score: %d\n", currentPtr->id,currentPtr->score);
        currentPtr = currentPtr->pPtr;
    }
  }
}