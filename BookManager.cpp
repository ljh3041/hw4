#include "BookManager.h"
#include <iostream>
#include <string>
bool BookManager::addBook(const string& title, const string& author) {
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].title == title)
        {
            cout << "�̹� ��ϵǾ� �ִ� å�Դϴ�.\n";
            return false;
        }
    }
    books.push_back(Book(title, author));
    cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    return true;
}

// ��� å ��� �޼���
void BookManager::displayAllBooks() const
{
    if (books.empty()) {
        cout << "���� ��ϵ� å�� �����ϴ�." << endl;
        return;
    }

    cout << "���� ���� ���:" << endl;
    for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
        cout << "- " << books[i].title << " by " << books[i].author << endl;
    }
}

void BookManager::searchByTitle(string title)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].title == title)
        {
            cout << "�� å�� �۰��� " << books[i].author << endl;
            break;
        }
    }
}
void BookManager::searchByAuthor(string author)
{
    int count = 0;
    for (int i = 0; i < books.size(); i++)
    {
        cout << "�� �۰��� å�� \n";
        if (books[i].author == author)
        {
            count++;
            cout << i << " : " << books[i].title << endl;
        }
    }
    cout << "���� �� " << count << "���� �ֽ��ϴ�\n";
}


Book* BookManager::getBookByTitle(string title)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].title == title)
        {
            cout << books[i].title << " by " << books[i].author << endl;
            return &books[i];
        }
    }
    cout << "�׷����� �����ϴ�\n";
    return NULL;
}

Book* BookManager::getBookByAuthor(string author)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].author == author)
        {
            cout << books[i].title << " by " << books[i].author << endl;
            return &books[i];
        }
    }
    return NULL;
}