#include "List.h"

List::List()
{
	head = NULL;

}

bool List::emptyList() {

	if (head == NULL) {

		return true;
	}

	else
	{
		return false;
	}


}

void List::insertafter(int old, int New)
{
	node* current = head; //points on the current node

	if (head == NULL)
	{
		head = new node(New);
	}

	while (true) {


		if (current->get_val() == old) //once value found
		{
			node* Newnode = new node(New); //makes a new node

			Newnode->set_next(current->get_next()); //give node the address of the node withe previous one

			current->set_next(Newnode); //makes the old node store the address of the new node

			break;

		}
		else if (current->get_val() != old && current->get_next() != NULL) //if value not found and not endthen travers
		{
			current = current->get_next();



		}

		else if (current->get_next() == NULL)
		{
			node* Newnode = new node(New); //make a new node

			current->set_next(Newnode);
			Newnode->set_next(NULL);


			break;

		}

	}
}

void List::deleteNode(int value) {
	node* current = head;

	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}


	// Traverse the list to find the node before the one to be deleted
	while (current->get_next() != NULL) {
		if (current->get_next()->get_val() == value) {
			node* temp = current->get_next();
			current->set_next(temp->get_next());
			delete temp;
			return;
		}
		current = current->get_next();
	}


	cout << "Value: " << value << " not found in list" << endl;
}


void List::insert_begin(int value)
{
	if (head == NULL) {
		head = new node(value);
		head->set_next(NULL);
	}
	else {


		node* Newnode = new node(value); //making new node

		Newnode->set_next(head);
		head = Newnode;

	}



}

void List::insert_end(int value)
{
	node* current = head;
	node* Newnode = new node(value);
	Newnode->set_next(NULL);
	if (head == NULL)
	{
		head = Newnode;
		return;
	}
	while (true)
	{


		if (current->get_next() == NULL)
		{


			current->set_next(Newnode);

			break;

		}
		else
		{

			current = current->get_next();

		}

	}

}

void List::traverse()
{
	node* current = head;

	while (current != NULL)
	{




		cout << current->get_val() << endl;
		current = current->get_next();


	}

	if (head == NULL)
	{
		cout << "List is empty";
	}







}

int max_value(List a)
{
	int greatest = 0;
	node* current = a.head;

	if (a.head == NULL)
	{
		cout << "Empty List";
		return greatest;

	}

	while (current != NULL)
	{
		if (current->get_val() > greatest)
		{
			greatest = current->get_val();

		}
		else
		{

			current = current->get_next();


		}

	}

	return greatest;
}

void even_valued(List a)
{
	node* current = a.head;
	int count = 1;
	if (a.head == NULL)
	{
		cout << "Empty List";
		return;
	}

	while (current != NULL)
	{
		if ((count % 2) == 0)  //if count is even
		{
			cout << current->get_val() << endl; //print node

			

		}
	
			current = current->get_next(); //move to next node
			count++;//increas count 
		




	}




}
void half(List& a)
{
	node* current = a.head;
	int count = 0;

	if (a.head == NULL)
	{
		cout << "Empty" << endl;
		return;
	}

	// Count the total nodes
	while (current != NULL)
	{
		count++;
		current = current->get_next();
	}

	if (count % 2 != 0)
	{
		cout << "List doesn't have an even number of elements" << endl;
		return;
	}

	int half = count / 2;
	current = a.head;
	node* first_half_end = NULL;
	node* second_half_start = NULL;
	int pos = 1;

	// Find the end of the first half
	while (pos != half)
	{
		current = current->get_next();
		pos++;
	}

	first_half_end = current;
	second_half_start = current->get_next();
	first_half_end->set_next(NULL); // End the first half of the list

	// Find the end of the second half
	current = second_half_start;
	while (current->get_next() != NULL)
	{
		current = current->get_next();
	}

	current->set_next(a.head); // Connect the end of the second half to the start of the first half

	
	a.head = second_half_start;
}



void main()
{
	List* a = new List;
	a->insert_end(1);
	a->insert_end(2);
	a->insert_end(3);
	a->insert_end(4);

	
	
	even_valued(*a);








}