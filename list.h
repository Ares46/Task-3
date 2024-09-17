#include"node.h"

class List
{
private:

	node* head;

public:
	List();


	bool emptyList();

	void insertafter(int oldV, int newV);

	void deleteNode(int value);

	void insert_begin(int value);

	void insert_end(int value);

	void traverse();

	friend int max_value(List);
	friend void even_valued(List);
	friend void half(List&);


};



