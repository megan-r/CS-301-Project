#include<iostream>
using namespace std;

class Customer{
public:
	string Register;
	int Ticket;
	Customer *next;
	Customer(const string Register, int Ticket, Customer* pointer = NULL)
	{
		this->Register = Register;
		this->Ticket = Ticket;
		this->next = pointer;
	}
};
class classTicket
{
    private:
        Customer *head;
    public:
        classTicket();
        ~classTicket();
        void Porter();
        void SOB();
        void Remove();
        void Retrieve();
        void display();
        void Sum();
};


