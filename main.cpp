//Giovanni Jimenez
//12-10-2023
//Exam 3 - STLContainers
//CMPR 121

#include<iostream>
#include"input.h"
#include"Rational.h"
#include<vector>
#include<list>	
#include<stack>
#include<queue>
#include<Windows.h>
#include<algorithm>

using namespace std;

enum Colors { blue = 9, green = 10, white = 15, red = 4, violet = 13, cyan = 11};

//Function Prototypes:
char menuOptions();
void setConsoleColor(int color);
Rational getNewRationalNumber();

//Vector Functions:
void vectorOption();
int vectorOptions();

//List Functions:
void listOption();
int listOptions();

//Stack Functions:
void stackOption();
int stackOptions();
void PrintStack(stack<Rational> s);

//Queue Functions:
void queueOption();
int queueOptions();
void PrintQueue(queue<Rational> q);

int main()
{
	do
	{
		setConsoleColor(white);
		system("cls");
		cout << "\n\tA container is a holder object that stores a collection of other objects (its elements). They";
		cout << "\n\tare implented as class templates, which allows great flexibility in the types supported as";
		cout << "\n\telements. The container manages the stores space for its elements and provides member functions";
		cout << "\n\tto access them, either directly or through iterators (reference objects with similar properties";
		cout << "\n\tto pointers).\n";

		cout << "\n\tExam 3: STL (Standard Template Library) Containers and Container Adaptors by Giovanni Jimenez";
		cout << "\n\t" << string(100, 205);

		switch (menuOptions())
		{
		case 'X': 
			exit(0); break;
		case 'V':
			vectorOption(); break;
		case 'L':
			listOption(); break;
		case 'S':
			stackOption(); break;
		case 'Q':
			queueOption(); break;
		}
		

	} while (true);

	cout << '\n';
	system("pause");
	return 0;
}

char menuOptions()
{
	cout << "\n\t\tV. Vector Container";
	cout << "\n\t\tL. List Container";
	cout << "\n\t\tS. Stack Container Adaptor";
	cout << "\n\t\tQ. Queue Container Adaptor";
	cout << "\n\t" << string(100, 196);
	cout << "\n\t\tX. Exit";
	cout << "\n\t" << string(100, 205);

	return inputChar("\n\t\tOption: ");
}

Rational getNewRationalNumber()
{

	try
	{
		cout << "\n\tInput a rational number to be added...";

		int numerator, denominator;
		numerator = inputInteger("\n\t\tEnter a numerator(-9...9)	:", -9, 9);
		denominator = inputInteger("\n\t\tEnter a denominator(-9...9)	:", -9, 9);
		Rational temp(numerator,denominator);
		return temp;
	}
	catch (Rational::InvalidDenominator)
	{
		Rational temp(-10,1);
		cout << "\n\t\tERROR: Cannot set denominator to 0....";
		return temp;
	}
}

//USE INTERATORS FOR PRINTING NOT ARRAY INDEXING 
void vectorOption()
{
	vector<Rational> array;
	Rational number;
	//Change this to an iterator
	int index = 0;
	do
	{
		setConsoleColor(red);
		system("cls");
		cout << "\n\tVectors are the same as dynamic arrays with the ability to resize itself automatically when an";
		cout << "\n\telement is inserted or delted, with their storage being handled automatically by the container.";
		cout << "\n\tVector elements are placed in contigous storage so that they can be access and traversed";
		cout << "\n\tusing iterators or indexes.\n";

		setConsoleColor(white);

		if (!array.empty())
		{
			cout << "\n\tThe current vector contains " << array.size() << " elements: \n";
			cout << "\n";
			cout << "\tElements:\n";
			cout << "\t\t";

			//This is fine
			for (auto i : array)
			{
				cout << i.toString() << " ";
			}

			cout << "\n\n\tindex: ";
			for (int i = 0; i < array.size(); i++)
			{
				cout << "  " << i << " ";
			}

			cout << "\n\n\taddress: " << &array;
		}
		else
			cout << "\n\tThe current vector is empty.";

		cout << "\n\n\n\n";

		cout << "\n\t\tVector Menu Options";
		cout << "\n\t" << string(100, 205);

		switch (vectorOptions())
		{
		case 0:
			return; break;
		case 1:
			number = getNewRationalNumber();
			if (number.getNumerator() != -10)
			{
				cout << "\n\n\t\t" << number.toString() << " will be added to the back of the vector.\n\n";
				array.push_back(number);
				system("pause");
				break;
			}
			else
			{
				cout << "\n\n";
				system("pause");
				break;
			}
		case 2:
			number = getNewRationalNumber();
			index = inputInteger("\n\tEnter the index to add new element to (0..." + to_string(array.size()) + "): ");

			if (number.getNumerator() != -10)
			{
				cout << "\n\n\t\t" << number.toString() << " will be added to index: " + to_string(index) + "\n\n";
				if (array.empty())
				{
					array.push_back(number);
				}
				else
					array.insert(array.begin() + index, number);
				break;
			}
			else
				break;
		case 3:
			if (!array.empty())
			{
				index = inputInteger("\n\tEnter the index you wish to look at from (0..." + to_string(array.size() - 1) + "): ");
				number = array.at(index);
				cout << "\n\tAt index: " + to_string(index) + " is rational number: " + number.toString() << "\n\n";
				system("pause");
			}
			else
			{
				cout << "\n\tCannot index an empty array!\n\n";
				system("pause");
			}
			break;
		case 4:
			if (!array.empty())
			{
				number = getNewRationalNumber();
				if (number.getNumerator() == -10)
				{
					cout << "\n\n";
					system("pause");
					break;
				}

				char userChoice = inputChar("\n\tDo you want to remove (O-one or A-all) element(s): ", 'O', 'A');

				auto it = find(array.begin(), array.end(), number);
				if (it != array.end())
				{

					switch (userChoice)
					{
					case 'O':
						array.erase(it);
						cout << "\n\tElement " + number.toString() + " has been removed from the vector!\n\n";
						system("pause");
						break;
					case 'A':
						while (it != array.end())
						{
							array.erase(it);
							it = find(array.begin(), array.end(), number);
						}
						cout << "\n\tAll elements of " + number.toString() + " have been erased!\n\n";
						system("pause");
						break;
					}
				}
				else
				{
					cout << "\n\tCould not find " + number.toString() + " in the vector.\n\n";
					system("pause");
				}
			}
			else
			{
				cout << "\n\tCannot perform erase an element on an empty array!\n\n";
				system("pause");
			}
			break;
		case 5:
			if (!array.empty())
			{
				sort(array.begin(), array.end());
				cout << "\n\tVector has been sorted in ascending order!\n\n";
				system("pause");
			}
			else
			{
				cout << "\n\tCannot sort an empty array!\n\n";
				system("pause");
			}
			break;
		case 6:
			if (!array.empty())
			{
				array.clear();
				cout << "\n\tVector has been cleared of all data!\n\n";
				system("pause");
			}
			else
			{
				cout << "\n\tCannot clear an already empty vector!\n\n";
				system("pause");
			}
			break;
		}

	} while (true);

	system("pause");
}

int vectorOptions()
{
	cout << "\n\t\t1. Add an element to the back";
	cout << "\n\t\t2. Insert an element at an index";
	cout << "\n\t\t3. Retrieve an element at an index";
	cout << "\n\t\t4. Erase element(s)";
	cout << "\n\t\t5. Sort the elements in ascending order";
	cout << "\n\t\t6. Clear all elements";
	cout << "\n\t" << string(100, 196);
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(100, 205);

	return inputInteger("\n\t\tOption: ", 0,6);
}

void listOption()
{
	list<Rational> list;
	Rational number;
	char userChoice;
	Rational existingNumber;
	auto it = list.begin();
	do
	{
		system("cls");
		setConsoleColor(violet);
		cout << "\n\tLists are sequence containers thatt allow non-contigious memory allocation. As cmopared to";
		cout << "\n\tvectors, the list has slow traversal, but once a position has been found, insertion and";
		cout << "\n\tdeletion are quicker.";
		setConsoleColor(white);
		if (list.empty())
		{
			cout << "\n\n\tThe current list is empty.";
			cout << "\n\n\n\n";
		}
		else
		{
			cout << "\n\n\tThe current list has " << list.size() << " elements.";
			cout << "\n\n\t";
			for (auto it : list)
			{
				cout << it.toString() << " -> ";
			}
			cout << "\n\n\n\tAddress: " << &list;
			cout << "\n\n";
		}

		cout << "\n\t\tList Menu Options";
		cout << "\n\t" << string(100, 205);
		switch (listOptions())
		{
		case 0:
			return; break;
		case 1:
			number = getNewRationalNumber();

			if (number.getNumerator() != -10)
			{
				userChoice = inputChar("\n\tWould you like to add to the front (F) or back (B) of list: ", 'F', 'B');
				switch (userChoice)
				{
				case 'F':
					list.push_front(number);
					cout << "\n\tRational Number added to front of the linked list!\n";
					system("pause");
					break;
				case 'B':
					list.push_back(number);
					cout << "\n\tRational Number added to back of the linked list!\n";
					system("pause");
					break;
				}
			}
			else
			{
				cout << "\n\tNumber has not been added to the linked list!\n";
				system("pause");
			}
			break;
		case 2:

			//enter a new rational number
			number = getNewRationalNumber();

			//enter an existing rational number
			existingNumber = getNewRationalNumber();

			if (number.getNumerator() == -10 || existingNumber.getNumerator() == -10)
			{
				cout << "\n\n";
				system("pause");
				break;
			}

			//ask to to insert before or after existing rational number

			userChoice = inputChar("\n\tInsert (B-before) or (A-after) the existing element: ", 'B', 'A');

			it = find(list.begin(), list.end(), existingNumber);

			if (it == list.end())
			{
				cout << "\n\tCould not find Rational Number " << existingNumber.toString() << " in the list!\n\n";
				system("pause");
				break;
			}

			switch (userChoice)
			{
			case 'B':
				list.insert(--it, number);
				cout << "\n\tNumber " << number.toString() << " has been added to the list!\n\n";
				system("pause");
				break;
			case 'A':
				list.insert(++it, number);
				cout << "\n\tNumber " << number.toString() << " has been added to the list!\n\n";
				system("pause");
				break;
			}

			break;
		case 3:
			if (!list.empty())
			{
				number = getNewRationalNumber();
				if (number.getNumerator() == -10)
				{
					cout << "\n\n";
					system("pause");
					break;
				}

				userChoice = inputChar("\n\tDelete (O - One or A - All) elements from list: ", 'O', 'A');

				auto it = find(list.begin(), list.end(), number);
				
				if (it != list.end())
				{
					switch (userChoice)
					{
					case 'O':
						list.erase(it);
						cout << "\n\tRational Number " << number.toString() << " has been removed from the list!\n\n";
						system("pause");
						break;
					case 'A':
						while (it != list.end())
						{
							list.erase(it);
							it = find(list.begin(), list.end(), number);
						}
						cout << "\n\tAll Rational Numbers " << number.toString() << " have been removed from the list!\n\n";
						system("pause");
						break;
					}
				}
				else
				{
					cout << "\n\tCould not find Rational Number " << number.toString() << " in list \n\n";
					system("pause");
				}
			}
			else
			{
				cout << "\n\tCannot delete elements from an empty list!\n\n";
				system("pause");
			}
			break;
		case 4:
			if (!list.empty())
			{
				list.sort();
				cout << "\n\tThe list has been sorted in ascending order!\n\n";
				system("pause");
				break;
			}
			else
			{
				cout << "\n\tCannot sort an empty list!\n\n";
				system("pause");
				break;
			}
		case 5:
			if (!list.empty())
			{
				list.clear();
				cout << "\n\tThe list has been cleared of all elements!\n\n";
				system("pause");
				break;
			}
			else
			{
				cout << "\n\tCannot clear an empty list!\n\n";
				system("pause");
				break;
			}
		}


	} while (true);
}

int listOptions()
{
	cout << "\n\t\t1. Add an element";
	cout << "\n\t\t2. Insert an element after";
	cout << "\n\t\t3. Remove elements(s)";
	cout << "\n\t\t4. Sort the elements in ascending order";
	cout << "\n\t\t5. Clear all elements";
	cout << "\n\t" << string(100, 196);
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(100, 205);
	return inputInteger("\n\tOption: ", 0, 6);
}

void PrintStack(stack<Rational> s)
{
	if (s.empty())
		return;

	Rational x = s.top();

	s.pop();

	PrintStack(s);

	cout << " " << x.toString() << " ";

	s.push(x);
}



//TODO: PRINT THE STACK USING RECURSION NOT A VECTOR
void stackOption()
{
	stack<Rational> stack;
	Rational number;

	do
	{
		system("cls");
		setConsoleColor(cyan);
		cout << "\n\tStacks are type of container adaptors with LIFO (Last in First Out) type of working, where";
		cout << "\n\ta new element is added (push) at one end (top) and an element is removed (pop) from that end";
		cout << "\n\tonly. Stack uses and encapsulated object of either vector or deque (by default) or list (sequential";
		cout << "\n\tcontainer class) as its underlying container, providing a specific set of member functions to";
		cout << "\n\taccess its elements.\n";
		cout << "\n";
		setConsoleColor(white);

		if (stack.empty())
		{
			cout << "\n\tThe current stack is empty.";
			cout << "\n\n\n\n\n";
		}
		else
		{
			cout << "\n\tThe current stack contains " << to_string(stack.size()) << " elements";
			cout << "\n\t\t";
			PrintStack(stack);
			cout << "<-- TOP";
			cout << "\n\n";
		}
		cout << "\n\t\tStack Menu Options";
		cout << "\n\t" << string(100, 205);

		switch (stackOptions())
		{
		case 0:
			return; break;
		case 1:
			//get a new rational number
			number = getNewRationalNumber();
			if (number.getNumerator() == -10)
			{
				cout << "\n\n";
				system("pause");
				break;
			}

			//push new ratioal number
			stack.push(number);
			cout << "\n\tNumber " << number.toString() << " has been pushed to the stack!\n\n";
			system("pause");
			break;
		case 2:
			//Check if stack is empty
			if (!stack.empty())
			{
				//show top element
				cout << "\n\tNumber " << stack.top().toString() << " is the top element\n\n";
				system("pause");
				break;
			}
			else
			{
				cout << "\n\tCannot perform top operation on an empty stack!\n\n";
				system("pause");
				break;
			}
			break;
		case 3:
			if (!stack.empty())
			{
				stack.pop();
				cout << "\n\tThe top element in the stack has been removed!\n\n";
				system("pause");
				break;
			}
			else
			{
				cout << "\n\tCannot perform pop operaton on an empty stack!\n\n";
				system("pause");
				break;
			}
			break;

		}

	} while (true);
}

int stackOptions()
{
	cout << "\n\t\t1. Push";
	cout << "\n\t\t2. Top";
	cout << "\n\t\t3. Pop";
	cout << "\n\t" << string(100, 196);
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(100, 205);

	return inputInteger("\n\tOption: ", 0, 3);
}

void PrintQueue(queue<Rational> q)
{
	if (q.empty())
		return;

	Rational x = q.front();

	q.pop();

	PrintQueue(q);

	cout << " " << x.toString() << " ";

	q.push(x);
}

//PRINT THE QUEUE USING RECURSION AND NOT A VECTOR!
void queueOption()
{
	queue<Rational> queue;
	Rational number;
	do
	{
		system("cls");
		setConsoleColor(green);
		cout << "\n\tQueues are a type of container adaptors that operate in a first in first out (FIFO) type of";
		cout << "\n\tarrangement. Elements are inserted (enqueued) at the back and are deleted (dequeued) from the";
		cout << "\n\tfront. Queues use an encapsulated object of deque or list (sequestial container class) as its";
		cout << "\n\tunderlying container, providing specific set of member functions to access elements.\n";
		setConsoleColor(white);
		//Change this to pring using recursion in the else block
		if (queue.empty())
		{
			cout << "\n\tThe current queue is empty";
			cout << "\n\n\n\n\n";
		}
		else
		{
			cout << "\n\tThe current queue contains " << to_string(queue.size()) << " elements";
			cout << "\n\n";
			cout << "\t\tBack -> ";
			PrintQueue(queue);
			cout << " -> Front";
		}

		cout << "\n\t\tQueue Menu Options";
		cout << "\n\t" << string(100, 205);

		switch (queueOptions())
		{
		case 0: 
			return; break;
		case 1:
			//get new rational number
			number = getNewRationalNumber();

			if (number.getNumerator() == -10)
			{
				cout << "\n\n";
				system("pause");
				break;
			}
			//add to queue
			queue.push(number);
			cout << "\n\tNumber " << number.toString() << " has been enqueued!\n\n";
			system("pause");
			break;

		case 2:
			//check queue empty
			if (!queue.empty())
			{
				//output first element;
				cout << "\n\tNumber " << queue.front().toString() << " is the first element in the queue\n\n";
				system("pause");
			}
			else
			{
				cout << "\n\tCannot show first element of empty queue!\n\n";
				system("pause");
			}
			break;

		case 3:
			//check queue empty
			if (!queue.empty())
			{
				//output last element
				cout << "\n\tNumber	" << queue.back().toString() << " is the last element in the queue\n\n";
				system("pause");
			}
			else
			{
				cout << "\n\tCannot show last element of empty queue!\n\n";
				system("pause");
			}
			break;

		case 4:
			//check queue empty
			if (!queue.empty())
			{
				//push first element out
				cout << "\n\tNumber " << queue.front().toString() << " has been dequed from the queue!\n\n";
				queue.pop();
				system("pause");
			}
			else
			{
				cout << "\n\tCannot show last element of empty queue!\n\n";
				system("pause");
			}
			break;
		}
	} while (true);
}

int queueOptions()
{
	cout << "\n\t\t1. Enqueue (push in from the back)";
	cout << "\n\t\t2. Front";
	cout << "\n\t\t3. Back";
	cout << "\n\t\t4. Dequeue (pop from the front)";
	cout << "\n\t" << string(100, 196);
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(100, 205);

	return inputInteger("\n\t\tOption: ");
}

void setConsoleColor(int color)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
}