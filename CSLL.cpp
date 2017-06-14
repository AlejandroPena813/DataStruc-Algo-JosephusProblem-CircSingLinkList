#include "CSLL.h"


template <typename T>
CSLL<T>::CSLL(){

  head = 0;
  sizeOfList = 0;
}

template <typename T>
CSLL<T>::~CSLL(){

  while(head != NULL) {
    Node * n = head->next;
    delete head;
    head = n;
        }
}

template <typename T>
typename CSLL<T>::Node* CSLL<T>::traverse_list(int position){

  Node* conductor = head;

  for(int i = 0; i<position; i++){
    conductor = conductor->next;
  }
  
  return conductor;
}

template <typename T>
void CSLL<T>::insert(const T& element, int position){

	if(position == 0){				//if appended at the end?
	Node * elnode = new Node;
  elnode->x = element;
	elnode->next = head; //what if list empty
  head = elnode; 
  sizeOfList++;
		
}

	else{
		Node * elnode = new Node;
    elnode->next = traverse_list(position);
    elnode->x = element;
    traverse_list(position-1)->next = elnode;
    sizeOfList++;
}
}

template <typename T>
T CSLL<T>::remove( int position){

	T a;
	if(position < sizeOfList){
		a = traverse_list(position)->x;

		if(position >0){
	  	Node* elnode = traverse_list(position);
	  	traverse_list(position-1)->next = traverse_list(position+1);
	  	delete elnode;
}
		if(position == 0){
			Node * elnode = head;
			head= head->next;
			delete elnode;
}

		//check if position greater than size,***later consider throw/catch exceptions
  sizeOfList--;
	return a;
}
	else{
	a = 0;
	cout<< "Position is bigger than size of linked list"<<endl;
	return a;
}
  
}

template <typename T>
T CSLL<T>::item_at( int position){

	return traverse_list(position)->x;

}

template <typename T>
ostream& CSLL<T>::print(ostream& out){

	int i = 0;
	if(sizeOfList == 0){	
	out<< "<empty list>";
	return out;    

}

	else{
	out<< '[';

	while(traverse_list(i) != 0){
	
		if(i ==sizeOfList-1){
			out<<traverse_list(i)->x;

}
	
		else{
			out<< traverse_list(i)->x <<',';
}	
		i++;
}
	out<< ']';

	return out;}
}
  



int main(){
  
CSLL<int> obj;
int i = 1;
obj.insert(i,0);
obj.insert(3,1);
obj.insert(2,2);
obj.print(cout)<<endl;

obj.remove(1);
cout<<"item at"<<obj.item_at(1);
  
  
  
  
  return 0;

}
