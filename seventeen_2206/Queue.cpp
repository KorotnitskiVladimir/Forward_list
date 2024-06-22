#include <iostream>
#include <ppltasks.h>
using namespace std;


struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();

	void addIndex(char data, int index);
	void remove(int index);
	void removeLast();
	int findPos(char s);
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::addIndex(char data, int index)
{
	Element* temp = Head;
	int i = 1;
	while (i<index)
	{
		temp = temp->Next;
		i++;
	}
	Element* NewNode = new Element;
	NewNode->data = data;
	NewNode->Next = temp->Next;
	temp->Next = NewNode;
}

void List::remove(int index)
{
	Element* temp = Head;
	int i=1;
	while (i<index)
	{
		temp = temp->Next;
		i++;
	}
	Element* t = temp->Next;
	temp->Next = t->Next;
	delete t;
}

void List::removeLast()
{
	Element* temp = Head;
	while (temp->Next!=Tail)
		temp = temp->Next;
	
	delete Tail;
	Tail = temp;
	Tail->Next = NULL;
}

int List::findPos(char s)
{
	int ind = 0;
	int i = 0;
	Element* t = Head;
	while(t!=NULL)
	{
		if (t->data == s)
		{
			ind = i;
			break;
		}
		t = t->Next;
		i++;
	}
	return ind;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	delete temp;
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != NULL)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}

// �������� ������
int main()
{
	// ������� ������ ������ List
	List lst;

	// �������� ������
	char s[] = "Hello, World !";
	// ������� ������
	/*
	 cout << s << "\n\n";
	// ���������� ����� ������
	*/
	int len = strlen(s);
	//�������� ������ � ������
	
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	/*
	// ������������� ���������� ������
	lst.Print();
	// ������� ��� �������� ������
	lst.Del();
	lst.Del();
	lst.Del();
	//������������� ���������� ������
	lst.Print();
	lst.remove(2);
	lst.Print();
	*/
	lst.removeLast();
	lst.Print();
	cout << lst.findPos('l');

	return 0;
}

