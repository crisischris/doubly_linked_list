#ifndef   LINKEDLIST_HPP
#define   LINKEDLIST_HPP

class LinkedList
{
  public:
	LinkedList();
	~LinkedList();
  void add(int);
  void addTail(int);
  void addHead(int);
	void remove(int);
	void removeHead();
	void removeTail();
	void displayReverse();
	void display();
	void displayTail();
	void displayHead();


  protected:
  struct NodeList
  {
 		int val;
		NodeList* next;
		NodeList* prev;
  	NodeList(int inVal, NodeList* inNext = NULL)
		{
			val = inVal;	
			next = inNext;
		}
	};
	NodeList* head;

  private:


};
#endif

