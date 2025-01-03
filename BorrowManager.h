#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include <unordered_map>

class BorrowManager
{
private:
    unordered_map<string, int> stock; // 빌린책 목록 저장

public:
    void initializeStock(Book book, int quantity = 3);
    
    //책 제거 메서드 => 반납
    void returnBook(string title);
    // 책 추가 메서드 => 대출처리
    void borrowBook(string title);

    void displayStock();
    
};