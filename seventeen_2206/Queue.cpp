#include <iostream>
#include <ppltasks.h>
using namespace std;


struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();

	void addIndex(char data, int index);
	void remove(int index);
	void removeLast();
	int findPos(char s);
};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
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
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != NULL)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}

// Тестовый пример
int main()
{
	// Создаем объект класса List
	List lst;

	// Тестовая строка
	char s[] = "Hello, World !";
	// Выводим строку
	/*
	 cout << s << "\n\n";
	// Определяем длину строки
	*/
	int len = strlen(s);
	//Загоняем строку в список
	
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	/*
	// Распечатываем содержимое списка
	lst.Print();
	// Удаляем три элемента списка
	lst.Del();
	lst.Del();
	lst.Del();
	//Распечатываем содержимое списка
	lst.Print();
	lst.remove(2);
	lst.Print();
	*/
	lst.removeLast();
	lst.Print();
	cout << lst.findPos('l');

	return 0;
}

