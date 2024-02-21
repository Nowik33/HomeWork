// dz_240223.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// реализовать двусвязный список
#include <iostream>
using namespace std;

template<typename T>
struct Node 
{
    T value;
    Node* next;
    Node* prev;
};

template<typename T>
class LinkedList 
{
    Node<T> * head = nullptr;
    Node<T> * tail = nullptr;
public:
    void push_front(T value)
    {
        Node<T>* newNode = new Node<T>{ value };
        newNode->next = head;
        if (head != nullptr) head->prev = newNode;
        if (tail == nullptr) tail = newNode;
        newNode->prev = nullptr;
        head = newNode;
    }
    void push_back(T value)
    {
        Node<T>* newNode = new Node<T>{ value };
        newNode->prev = tail;
        if(tail != nullptr) tail->next = newNode;
        if (head == nullptr) head = newNode;
        newNode->next = nullptr;
        tail = newNode;
    }
    void insert(T value,  int index) 
    {
        Node<T>* bufl = head;
        for (int i = 0; i < index-1;i++) 
        {
            bufl = bufl->next;
        }
        Node<T>* bufr = bufl->next;
        Node<T>* newNode = new Node<T>{ value };
        bufl->next = newNode;
        newNode->prev = bufl;
        newNode->next = bufr;
        bufr->prev = newNode;
    }
    void dropEl(int index)
    {
        Node<T>* bufl = head;
        for (int i = 0; i < index-1; i++)
        {
            bufl = bufl->next;
        }
        Node<T>* bufr = bufl->next->next;
        bufl->next = bufr;
        bufr->prev = bufl;
    }
    void showAll()
    {
        Node<T>* buf = head;
        while (buf->next != nullptr)
        {
            cout << buf->value << " ";
            buf = buf->next;
        }
        cout << buf->value;
        cout << endl;

        Node<T>* buff = tail;
        while (buff->prev != nullptr)
        {
            cout << buff->value << " ";
            buff = buff->prev;
        }
        cout << buff->value;
        cout << endl;
    }
};

int main()
{
    LinkedList<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.push_front(i);
    }

    for (int i = 10; i < 20; i++)
    {
        list.push_back(i);
    }

    list.showAll();

    list.insert(100, 3);
    list.showAll();

    list.dropEl(3);
    list.showAll();
}

