#include <iostream>

#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"
using namespace std; // namespace std 사용



//가정 - BookManager, BorrowBookManager
//
//책의 정보가 한번 등록되면, 삭제되지 않는다.
//여기서는 책이 몇권이 있는지는 알 필요가 없다.
//책이 몇권이 있는지는 BorrorwManager에서 확인한다.
//BorrowManager 또한 책이 추가되면 더 이상 목록에서 삭제하지 않는다.
//특정 책이 대출 가능한지는 BorrowManager에서 책의 갯수를 살펴봄으로써 정보를 얻는다.
//BorrowBookManager의 initializeStock 함수의 경우 book을 받게 되는데, 
//  이는 BookManager에서 Add가 호출되면 같이 호출되도록 한다.(책 재고는 3권 고정)
//borrowBook, returnBook의 경우, 해당 타이틀을 찾아 대출 수를 올리고 내리는 동작만 하며,
//  0~3 범위를 벗어날 때의 동작만 체크하여 제어한다.
//displayStock 함수는 map을 전부 돌면서 타이틀과 대출 수를 프린트한다.








int main() {
    BookManager manager;
    BorrowManager BorrowManager;
    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 책 대출" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 반납" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "4. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "5. 종료" << endl; // 프로그램 종료
        cout << "선택: ";
        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cin.ignore();
            cout << "책 제목: ";
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            if (manager.addBook(title, author))
            {
                // 입력받은 책 정보를 추가
                BorrowManager.initializeStock(Book(title, author));
            }
        }
        else if (choice == 2) {
            // 2번 선택: 책 대출
            cout << "대출할 책의 이름을 적으려면 1번, 대출할 작가의 이름을 적으려면 2번을 입력하세요.\n";
            int index = 0;
            cin >> index;
            string str;
            Book* borrow = nullptr;
            if (index == 1)
            {
                //책 이름
                cout << "대출하고 싶으신 책의 이름을 적어주세요.\n";
                cin.ignore();
                getline(cin, str);
                borrow = manager.getBookByTitle(str);
            }
            else if (index == 2)
            {
                //저자 이름
                cout << "저자의 이름을 적어주세요.\n";
                cin.ignore();
                getline(cin, str);
                borrow = manager.getBookByAuthor(str);
            }
            else
            {
                //지정 범위 바깥
                //while (std::cin.get() == '\n') continue;
                cout << "1 또는 2를 입력해야합니다. 처음으로 돌아갑니다.\n";
            }
            if (borrow != nullptr)
            {
                BorrowManager.borrowBook(borrow->title);
            }
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else if (choice == 3) {
            // 4번 선택: 책 반납
            cout << "반납할 책의 이름을 적으려면 1번, 작가의 이름을 적으려면 2번을 입력하세요.\n";
            int index = 0;
            cin >> index;
            string str;
            Book* returnBook;
            if (index == 1)
            {
                //책 이름
                cout << "반납하고 싶으신 책의 이름을 적어주세요.\n";
                cin.ignore();
                getline(cin, str);
                returnBook = manager.getBookByTitle(str);
            }
            else if (index == 2)
            {
                //저자 이름
                cout << "저자의 이름을 적어주세요.\n";
                cin.ignore();
                getline(cin, str);
                returnBook = manager.getBookByAuthor(str);
            }
            else
            {
                //지정 범위 바깥
                cout << "1 또는 2를 입력해야합니다. 처음으로 돌아갑니다.\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                continue;
            }
            BorrowManager.returnBook(returnBook->title);
        }
        else if (choice == 4) {
            // 4번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 5) {
            // 5번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    return 0; // 프로그램 정상 종료
}