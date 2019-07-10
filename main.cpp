#include "header.h"
#include<iostream>
#include<string>
using namespace std;

classTicket::classTicket()
{
	head = NULL;
}
classTicket::~classTicket()
{
}
void classTicket::Sum()
{
	Customer* Consumer = head;
	int sum = 0;
	while (Consumer != NULL)
	{
		cout << "Attendee:" << Consumer->Register << endl;
		cout << "Price:" << Consumer->Ticket << endl;
		sum += Consumer->Ticket;
		Consumer = Consumer->next;
	}
	cout << "Total Cost = " << sum *1.0975 << endl;
}
void classTicket::Porter()
{
	string Register;
	cout << "Attendee:" << endl;
	cin >> Register;
	if (head == NULL)
	{
		head = new Customer(Register, 333);
		cout << "Ticket Added to Cart." << endl;
		return;
	}
	else
	{
		Customer *Consumer = head;
		while (Consumer->next)
		{
			if (Register < Consumer->Register)
				break;
			else
				Consumer = Consumer->next;
		}
		Consumer->next = new Customer(Register, 333, Consumer->next);
		cout << "" << endl;
		return;
	}
}
void classTicket::SOB()
{
	string Register;
	cout << "Attendee:" << endl;
	cin >> Register;
	if (head == NULL)
	{
		head = new Customer(Register, 600);
		cout << "Ticket Added to Cart." << endl;
		return;
	}
	else
	{
		Customer *Consumer = head;
		while (Consumer->next)
		{
			if (Register < Consumer->Register)
				break;
			else
				Consumer = Consumer->next;
		}
		Consumer->next = new Customer(Register, 600, Consumer->next);
		cout << "" << endl;
		return;
	}
}
void classTicket::Remove()
{
	string Register;
	cout << "Attendee:" << endl;
	cin >> Register;

	Customer *Consumer = head, *TempConsumer = head;
	if (Consumer->Register == Register)
	{
		head = head->next;
		cout << "Ticket Cancelled." << endl;
		delete Consumer;
		return;
	}
	Consumer = head->next;
	while (Consumer)
	{
		if (Consumer->Register == Register)
		{
			TempConsumer->next = Consumer->next;
			delete Consumer;
			cout << "Ticket Removed." << endl;
			return;
		}
		else
		{
			TempConsumer = Consumer;
			Consumer = Consumer->next;
		}
	}
	cout << "" << endl;
	cout << "Ticket not registered." << endl;
	return;
}
void classTicket::Retrieve()
{
	string Register;
	cout << "Attendee:" << endl;
	cin >> Register;
	Customer* Consumer = head;
	if (Consumer == NULL)
	{
		cout << "No Tickets." << endl;
	}
	while (Consumer != NULL)
	{
		if (Consumer->Register == Register)
		{
			cout << "Attendee:" << Consumer->Register << endl;
			cout << " Price:" << Consumer->Ticket << endl;
			return;
		}
		else
			Consumer = Consumer->next;
		cout << "Not Found." << endl;
	}
	return;
}
void classTicket::display()
{
	Customer* Consumer = head;
	while (Consumer != NULL)
	{
		cout << "Attendee:" << Consumer->Register << endl;
		cout << "Price:" << Consumer->Ticket << endl;
		Consumer = Consumer->next;
	}
}
int main()
{
	classTicket connect;
	while (true)
	{
		cout << "==============================" << endl;
		cout << "Ticket Purchases:" << endl;
		cout << "Enter Your Choice" << endl;
		cout << "1.Add ticket to Porter Robinson" << endl;
		cout << "2.Add ticket to SOB x RBE" << endl;
		cout << "3.Cancel a ticket" << endl;
		cout << "4.Check tickets" << endl;
		cout << "5.Show Cart" << endl;
		cout << "6.Checkout" << endl;
		cout << "7.End" << endl;
		cout << "==============================" << endl;

		int option;
		cin >> option;
		switch (option)
		{
		case 1:
			connect.Porter();
			break;
		case 2:
			connect.SOB();
			break;
		case 3:
			connect.Remove();
			break;
		case 4:
			connect.Retrieve();
			break;
		case 5:
			connect.display();
			break;
		case 6:
			connect.Sum();
			break;
		case 7:
		    cout << "You've exited out of the program." << endl;
			return 0;
		default:
			cout << "Invalid Input." << endl;
			break;
		}
	}
	return 0;
}



