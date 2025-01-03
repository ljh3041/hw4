#include "BorrowManager.h"
#include <iostream>
#include <string>
void BorrowManager::initializeStock(Book book, int quantity)
{
    if (stock.find(book.title) == stock.end())
    {
        stock[book.title] = quantity;
    }
}
//å ���� �޼��� => �ݳ�
void BorrowManager::returnBook(string title) {
    auto it = stock.find(title);
    if (it != stock.end()) {
        it->second++;
    }
}
// å �߰� �޼��� => ����ó��
void BorrowManager::borrowBook(string title) {
    auto it = stock.find(title);
    if (it != stock.end())
    {
        if (it->second > 0) {
            it->second--;
            cout << "������ �Ϸ�Ǿ����ϴ�.\n";
        }
        else {
            cout << "å�� ��� �������� �ʽ��ϴ�.\n";
        }
    }
    else
    {
        cout << "��ϵ��� ���� å�Դϴ�.\n";
    }

}

void BorrowManager::displayStock()
{
    cout << "���� �������� ���� ���:" << endl;
    for (auto it : stock) { // �Ϲ����� for�� ���
        cout << " - " << it.first << " : " << it.second << "��" << endl;
    }
}