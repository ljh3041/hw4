#include <iostream>

#include "Book.h"
#include "BookManager.h"
#include "BorrowManager.h"
using namespace std; // namespace std ���



//���� - BookManager, BorrowBookManager
//
//å�� ������ �ѹ� ��ϵǸ�, �������� �ʴ´�.
//���⼭�� å�� ����� �ִ����� �� �ʿ䰡 ����.
//å�� ����� �ִ����� BorrorwManager���� Ȯ���Ѵ�.
//BorrowManager ���� å�� �߰��Ǹ� �� �̻� ��Ͽ��� �������� �ʴ´�.
//Ư�� å�� ���� ���������� BorrowManager���� å�� ������ ���캽���ν� ������ ��´�.
//BorrowBookManager�� initializeStock �Լ��� ��� book�� �ް� �Ǵµ�, 
//  �̴� BookManager���� Add�� ȣ��Ǹ� ���� ȣ��ǵ��� �Ѵ�.(å ���� 3�� ����)
//borrowBook, returnBook�� ���, �ش� Ÿ��Ʋ�� ã�� ���� ���� �ø��� ������ ���۸� �ϸ�,
//  0~3 ������ ��� ���� ���۸� üũ�Ͽ� �����Ѵ�.
//displayStock �Լ��� map�� ���� ���鼭 Ÿ��Ʋ�� ���� ���� ����Ʈ�Ѵ�.








int main() {
    BookManager manager;
    BorrowManager BorrowManager;
    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. å ����" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �ݳ�" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "4. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "5. ����" << endl; // ���α׷� ����
        cout << "����: ";
        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cin.ignore();
            cout << "å ����: ";
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            if (manager.addBook(title, author))
            {
                // �Է¹��� å ������ �߰�
                BorrowManager.initializeStock(Book(title, author));
            }
        }
        else if (choice == 2) {
            // 2�� ����: å ����
            cout << "������ å�� �̸��� �������� 1��, ������ �۰��� �̸��� �������� 2���� �Է��ϼ���.\n";
            int index = 0;
            cin >> index;
            string str;
            Book* borrow = nullptr;
            if (index == 1)
            {
                //å �̸�
                cout << "�����ϰ� ������ å�� �̸��� �����ּ���.\n";
                cin.ignore();
                getline(cin, str);
                borrow = manager.getBookByTitle(str);
            }
            else if (index == 2)
            {
                //���� �̸�
                cout << "������ �̸��� �����ּ���.\n";
                cin.ignore();
                getline(cin, str);
                borrow = manager.getBookByAuthor(str);
            }
            else
            {
                //���� ���� �ٱ�
                //while (std::cin.get() == '\n') continue;
                cout << "1 �Ǵ� 2�� �Է��ؾ��մϴ�. ó������ ���ư��ϴ�.\n";
            }
            if (borrow != nullptr)
            {
                BorrowManager.borrowBook(borrow->title);
            }
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else if (choice == 3) {
            // 4�� ����: å �ݳ�
            cout << "�ݳ��� å�� �̸��� �������� 1��, �۰��� �̸��� �������� 2���� �Է��ϼ���.\n";
            int index = 0;
            cin >> index;
            string str;
            Book* returnBook;
            if (index == 1)
            {
                //å �̸�
                cout << "�ݳ��ϰ� ������ å�� �̸��� �����ּ���.\n";
                cin.ignore();
                getline(cin, str);
                returnBook = manager.getBookByTitle(str);
            }
            else if (index == 2)
            {
                //���� �̸�
                cout << "������ �̸��� �����ּ���.\n";
                cin.ignore();
                getline(cin, str);
                returnBook = manager.getBookByAuthor(str);
            }
            else
            {
                //���� ���� �ٱ�
                cout << "1 �Ǵ� 2�� �Է��ؾ��մϴ�. ó������ ���ư��ϴ�.\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                continue;
            }
            BorrowManager.returnBook(returnBook->title);
        }
        else if (choice == 4) {
            // 4�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 5) {
            // 5�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    return 0; // ���α׷� ���� ����
}