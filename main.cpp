/******************************************************************************
** Author: Chris Nelson 
** Date: 05.10.2019 
** Description: This is the main. Most of the logic is contained in the 
** LinkedList and Helper classes
******************************************************************************/

#include<iostream>
#include<fstream>
#include"Helper.hpp"
#include"LinkedList.hpp"

int main()
{
  
  std::ifstream inFile;
  std::string fileName = "numbers.txt";

  //declare strings here to for better looking code
  std::string menu1 = "Add a new node at the head";
	std::string menu2 = "Add a new node at the tail";
	std::string menu3 = "Delete the head node";
	std::string menu4 = "Delete the tail node";
	std::string menu5 = "traverse the list reversely";
	std::string menu6 = "Display head value";
	std::string menu7 = "Display tail value";

  LinkedList list;
  int listNum;
	int choice;
	
	Helper::splashScreen(" LINKED LIST ", 3);
	Helper::printMessage("NOTE: This project contains both extra credit tasks",2);

  //extra credit option
  choice = Helper::menu("Start you list by reading in supplied .txt file?", "No");
  if(choice == 1)
	{
		inFile.open(fileName);

		if(!inFile)
  	{
  	  std::cout << "There is no file named " << fileName << std::endl;
			return 0;
  	}

 	 int current;

		while(inFile >> current)
  	{ 
			list.add(current);
  	}
		Helper::newLine(1);
		std::cout << "***  CURRENT LIST ***" << std::endl;
		list.display();
		Helper::newLine(3);
		inFile.close();
	}

  //run until user exits
	while(true)	
	{
  	choice = Helper::menu(menu1, menu2, menu3, menu4, menu5, menu6, menu7, "Exit");
		switch(choice)
		{
			case 1:
			{
				Helper::printMessage("Enter an integer you would like to add to the head of your list",1);
     	  listNum = Helper::getInt(0);	
			  list.addHead(listNum);
				break;
			}

			case 2:
			{
				Helper::printMessage("Enter an integer you would like to add to the tail of your list",1);
     	  listNum = Helper::getInt(0);	
			  list.addTail(listNum);
				break;
			}
	    case 3:
			{
			  list.removeHead();
				break;
			}
	    case 4:
			{
			  list.removeTail();
				break;
			}
	    case 5:
			{
				Helper::printMessage("printing list in reverse order",1);
				list.displayReverse();	
				Helper::newLine(1);
				break;
			}
 	    case 6:
			{
  			list.displayHead();
				break;
			}
  	  case 7:
			{
  			list.displayTail();
				break;
			}

  	  case 8:
			{
				std::cout << "Bye" << std::endl;
				return 0;
				break;
			}
		}
		
		//display the current status of the list
		Helper::newLine(2);
		std::cout << "***  CURRENT LIST ***" << std::endl;
		list.display();
		Helper::newLine(2);
	}
  return 0;
}
