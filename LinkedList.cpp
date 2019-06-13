/******************************************************************************
** Author: Chris Nelson 
** Date: 05.10.2019 
** Description: This is the linked list class.  This class creates a linked 
** structure for the user to manipulate 
******************************************************************************/

#include<iostream>
#include"LinkedList.hpp"
#include"Helper.hpp"



LinkedList::LinkedList()
{
  head = NULL;
}

LinkedList::~LinkedList()
{
	NodeList* nodePtr = head;

	while(nodePtr != NULL)
	{
		NodeList* garbabe = nodePtr;
		nodePtr = nodePtr->next;
 		delete garbabe;
	}
}

//****************************************************************************
//this funciton adds a node to the list
//****************************************************************************

void LinkedList::add(int in)
{
	if(head == NULL)
	{
		head = new NodeList(in);
		NodeList* currList = head;
		currList->prev = NULL;
		currList->next = NULL;
	}
	else
	{
		NodeList* nodePtr = head;
		while(nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = new NodeList(in);
    NodeList* currList = nodePtr->next;
    currList->prev = nodePtr;
	}

}

//****************************************************************************
//this funciton adds a node to the tail of the list
//****************************************************************************

void LinkedList::addTail(int in)
{
		NodeList* nodePtr = head;
		if(head == NULL)
		{
			add(in);
		}
		else
		{
			while(nodePtr->next != NULL)
			{
				nodePtr = nodePtr->next;
			}
	  //we've found the last node
		nodePtr->next = new NodeList(in);
    NodeList* currList = nodePtr->next;
    currList->prev = nodePtr;
	}

}

//****************************************************************************
//this funciton adds a node to the head of the list
//****************************************************************************

void LinkedList::addHead(int in)
{
  //adding head to the first array element
	if(head == NULL)
	{
		add(in);
	}
	else
	{
		NodeList* tempNext = head;
		NodeList* nodePtr = tempNext->prev;
		nodePtr = new NodeList(in);
		nodePtr->prev = NULL;
		nodePtr->next = tempNext; 
		tempNext->prev = nodePtr; 
		head = nodePtr;
	}
}


//****************************************************************************
//this funciton removes a node to the head of the list
//****************************************************************************

void LinkedList::removeHead()
{
	NodeList* nodePtr = head;

	//we have at least one item in our list
  if(head != NULL)
	{
  	//first item of the list
		head = nodePtr->next; 
		delete nodePtr;
	}
	else
	{
 		Helper::printMessage("Your list is empty!",1);	
	}
}

//****************************************************************************
//this funciton removes a node to the tail of the list
//****************************************************************************

void LinkedList::removeTail()
{
	NodeList* nodePtr = head;

	//list is empty
  if(head == NULL)
	{
 		Helper::printMessage("Your list is empty!",1);	
	}

	else
	{
		while(nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}

		//one item in the list
		if(nodePtr->prev == NULL)
		{
			head = NULL;
			delete nodePtr;
		}
		//there is more than one item in list
		else
		{
			NodeList* temp = nodePtr->prev;
			delete nodePtr;
			temp->next = NULL;
		}
	}
}

//****************************************************************************
//this funciton removes a node to the tail of the list
//****************************************************************************

void LinkedList::remove(int in)
{
	NodeList* nodePtr = head;

  //first item of the list
  if(nodePtr->val == in)
	{
		head = nodePtr->next; 
		delete nodePtr;
	}
	else
	{
		while(nodePtr->next != NULL && nodePtr->val != in)
		{
				nodePtr = nodePtr->next;
		}
			//we have found a node with the val
 		if(nodePtr->val = in)
		{
			if(nodePtr->next != NULL)
			{
				NodeList* tempNext = nodePtr->next;
				tempNext->prev = nodePtr->prev;
				NodeList* tempPrev = nodePtr->prev; 
				tempPrev->next = tempNext;
				delete nodePtr;
			}
    //this is the last node
			else
			{
				NodeList* tempPrev = nodePtr->prev; 
				tempPrev->next = NULL; 
				delete nodePtr;
			}
		}
	}
}


//****************************************************************************
//this funciton displays the list from head to tail
//****************************************************************************

void LinkedList::display()
{
	NodeList* nodePtr = head;
	if(nodePtr == NULL)
	{
		Helper::printMessage("Empty list",0);
	}
  while(nodePtr)
	{
		std::cout << nodePtr->val << " -> ";
		nodePtr = nodePtr->next;
	}
}

void LinkedList::displayReverse()
{
	NodeList* nodePtr = head;

  //traverse to the end of the list 
	while(nodePtr->next != NULL)
	{
  	nodePtr = nodePtr->next;
	}
  //found the end;
  while(nodePtr)
	{
		std::cout << nodePtr->val << " -> ";
		nodePtr = nodePtr->prev;
	}
}


//****************************************************************************
//this funciton displays the head value of the list 
//****************************************************************************

void LinkedList::displayHead()
{
  //adding head to the first array element
	if(head == NULL)
	{
 		Helper::printMessage("Your list is empty!",1);	
	}
	else
	{
		std::cout << "The value of head is: " << head->val << std::endl;
	}
}

//****************************************************************************
//this funciton displays the tail value of the list 
//****************************************************************************

void LinkedList::displayTail()
{
	NodeList* nodePtr = head;

	//list is empty
  if(head == NULL)
	{
 		Helper::printMessage("Your list is empty!",1);	
	}

	if(nodePtr->next == NULL)
	{
	  displayHead();	
	}

	else
	{
		while(nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}

		std::cout << "The value of tail is: " << nodePtr->val << std::endl;
	}
}

