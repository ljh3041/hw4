#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    bool addBook(const string& title, const string& author);

    // 모든 책 출력 메서드
    void displayAllBooks() const;
    
    void searchByTitle(string title);
    
    void searchByAuthor(string author);
    
    Book* getBookByTitle(string title);    

    Book* getBookByAuthor(string author);
};