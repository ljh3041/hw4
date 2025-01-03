#include "BookManager.h"
#include <iostream>
#include <string>
bool BookManager::addBook(const string& title, const string& author) {
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].title == title)
        {
            cout << "이미 등록되어 있는 책입니다.\n";
            return false;
        }
    }
    books.push_back(Book(title, author));
    cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    return true;
}

// 모든 책 출력 메서드
void BookManager::displayAllBooks() const
{
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    cout << "현재 도서 목록:" << endl;
    for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
        cout << "- " << books[i].title << " by " << books[i].author << endl;
    }
}

void BookManager::searchByTitle(string title)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].title == title)
        {
            cout << "이 책의 작가는 " << books[i].author << endl;
            break;
        }
    }
}
void BookManager::searchByAuthor(string author)
{
    int count = 0;
    for (int i = 0; i < books.size(); i++)
    {
        cout << "이 작가의 책은 \n";
        if (books[i].author == author)
        {
            count++;
            cout << i << " : " << books[i].title << endl;
        }
    }
    cout << "으로 총 " << count << "권이 있습니다\n";
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
    cout << "그런것은 없습니다\n";
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