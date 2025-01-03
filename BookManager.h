#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    bool addBook(const string& title, const string& author);

    // ��� å ��� �޼���
    void displayAllBooks() const;
    
    void searchByTitle(string title);
    
    void searchByAuthor(string author);
    
    Book* getBookByTitle(string title);    

    Book* getBookByAuthor(string author);
};