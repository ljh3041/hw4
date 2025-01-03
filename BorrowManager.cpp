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
//책 제거 메서드 => 반납
void BorrowManager::returnBook(string title) {
    auto it = stock.find(title);
    if (it != stock.end()) {
        it->second++;
    }
}
// 책 추가 메서드 => 대출처리
void BorrowManager::borrowBook(string title) {
    auto it = stock.find(title);
    if (it != stock.end())
    {
        if (it->second > 0) {
            it->second--;
            cout << "대출이 완료되었습니다.\n";
        }
        else {
            cout << "책의 재고가 남아있지 않습니다.\n";
        }
    }
    else
    {
        cout << "등록되지 않은 책입니다.\n";
    }

}

void BorrowManager::displayStock()
{
    cout << "현재 보관중인 도서 목록:" << endl;
    for (auto it : stock) { // 일반적인 for문 사용
        cout << " - " << it.first << " : " << it.second << "권" << endl;
    }
}