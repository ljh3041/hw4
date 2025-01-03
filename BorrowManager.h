#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
#include <unordered_map>

class BorrowManager
{
private:
    unordered_map<string, int> stock; // ����å ��� ����

public:
    void initializeStock(Book book, int quantity = 3);
    
    //å ���� �޼��� => �ݳ�
    void returnBook(string title);
    // å �߰� �޼��� => ����ó��
    void borrowBook(string title);

    void displayStock();
    
};