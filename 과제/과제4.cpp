#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
public:
    string title;
    string author;
    int stock; // stack -> stock으로 변경

    Book(const string& title, const string& author)
        : title(title), author(author), stock(3) { // 초기 재고 3권으로 설정
    }

    void print() const {
        // 검색 요청된 도서를 찾았다는 메시지와 함께 재고 정보도 출력
        std::cout << "검색 요청된 도서를 찾았습니다. -> 제목: " << title << ", 저자: " << author << ", 재고: " << stock << "권" << std::endl;
    }
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author));
        cout << "책이 추가되었습니다: " << title << " by " << author << " (재고: 3권)" << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) {
            // displayAllBooks에서는 간략한 정보만 출력
            cout << "- " << books[i].title << " by " << books[i].author << " (재고: " << books[i].stock << "권)" << endl;
        }
    }

    const Book* searchByTitle(const std::string& t) const {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.title == t;
            });

        if (it != books.end()) {
            return &(*it);
        }
        else {
            return nullptr;
        }
    }

    const Book* searchByWriter(const std::string& w) const {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.author == w;
            });

        if (it != books.end()) {
            return &(*it);
        }
        else {
            return nullptr;
        }
    }

    bool borrowBook(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(), [&](Book& book) {
            return book.title == title;
            });

        if (it != books.end()) {
            if (it->stock > 0) {
                it->stock--;
                std::cout << "'" << title << "' 책이 대여되었습니다. 남은 재고: " << it->stock << "권" << std::endl;
                return true;
            }
            else {
                std::cout << "'" << title << "' 책은 현재 재고가 없어 대여할 수 없습니다." << std::endl;
                return false;
            }
        }
        else {
            std::cout << "'" << title << "' 책을 찾을 수 없습니다." << std::endl;
            return false;
        }
    }

    // 파라미터 추가: 반납할 책의 제목을 받습니다.
    bool returnBook(const std::string& title) {
        // 책의 재고를 수정해야 하므로 비-const 이터레이터를 얻습니다.
        auto it = std::find_if(books.begin(), books.end(), [&](Book& book) {
            return book.title == title;
            });

        if (it != books.end()) {
            if (it->stock < 3) { // 최대 재고는 3권
                it->stock++; // 재고 증가
                std::cout << "'" << title << "' 책이 반납되었습니다. 현재 재고: " << it->stock << "권" << std::endl;
                return true;
            }
            else {
                std::cout << "'" << title << "' 책은 이미 최대 재고(3권)이므로 반납할 수 없습니다." << std::endl;
                return false;
            }
        }
        else {
            std::cout << "'" << title << "' 책을 찾을 수 없습니다." << std::endl;
            return false;
        }
    }
};

int main() {
    BookManager manager;

    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
        cout << "3. 책 제목으로 도서 검색" << endl;
        cout << "4. 책 저자로 도서 검색" << endl;
        cout << "5. 책 대여" << endl; // 메뉴 이름 명확화
        cout << "6. 책 반납" << endl; // 메뉴 이름 명확화
        cout << "7. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        string searchInput; // 검색 및 대여/반납에 사용될 입력 변수

        if (choice == 1) {
            string title, author;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            manager.addBook(title, author);
        }
        else if (choice == 2) {
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            cout << "검색할 책 제목: ";
            cin.ignore();
            getline(cin, searchInput);
            const Book* foundBook = manager.searchByTitle(searchInput);
            if (foundBook != nullptr) {
                foundBook->print(); // 재고 정보 포함된 print 호출
                if (foundBook->stock > 0) {
                    cout << "-> 현재 대여 가능합니다." << endl;
                }
                else {
                    cout << "-> 현재 대여 불가능합니다 (재고 없음)." << endl;
                }
            }
            else {
                cout << "'" << searchInput << "'(으)로 검색된 책을 찾을 수 없습니다." << endl;
            }
        }
        else if (choice == 4) {
            cout << "검색할 책 저자: ";
            cin.ignore();
            getline(cin, searchInput);
            const Book* foundBook = manager.searchByWriter(searchInput);
            if (foundBook != nullptr) {
                foundBook->print(); // 재고 정보 포함된 print 호출
                if (foundBook->stock > 0) {
                    cout << "-> 현재 대여 가능합니다." << endl;
                }
                else {
                    cout << "-> 현재 대여 불가능합니다 (재고 없음)." << endl;
                }
            }
            else {
                cout << "'" << searchInput << "' 저자의 책을 찾을 수 없습니다." << endl;
            }
        }
        else if (choice == 5) { // 책 대여 기능 구현
            cout << "대여할 책 제목: ";
            cin.ignore();
            getline(cin, searchInput);
            manager.borrowBook(searchInput); // manager의 borrowBook 호출
        }
        else if (choice == 6) { // 책 반납 기능 구현
            cout << "반납할 책 제목: ";
            cin.ignore();
            getline(cin, searchInput);
            manager.returnBook(searchInput); // manager의 returnBook 호출
        }
        else if (choice == 7) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}