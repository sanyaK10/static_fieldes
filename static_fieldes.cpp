#include <iostream>

class User {
private:
    char* name;
    char* passwd;
    int id;
public:
    static int nextId;
    static int getNextId() {
        return User::nextId;
    }

    User(const char* n, const char* p) : name(nullptr), passwd(nullptr), id(nextId++) {
        if (n != nullptr) {
            name = new char[strlen(n) + 1];
            strcpy_s(name, strlen(n) + 1, n);
        }
        else {
            name = new char[1];
            strcpy_s(name, 1, "");
        }

        if (p != nullptr) {
            passwd = new char[strlen(p) + 1];
            strcpy_s(passwd, strlen(p) + 1, p);
        }
        else {
            passwd = new char[1];
            strcpy_s(passwd, 1, "");
        }
    }
    User(const User& other) : name(nullptr), passwd(nullptr), id(other.id) {
        // Поверхневе копіювання (побітове копіювання)
        //this->name = other.name;
        //this->passwd = other.passwd;
        //this->id = other.id;

        // Глибоке копіювання
        this->name = new char[strlen(other.name) + 1];
        strcpy_s(this->name, strlen(other.name) + 1, other.name);

        this->passwd = new char[strlen(other.passwd) + 1];
        strcpy_s(this->passwd, strlen(other.passwd) + 1, other.passwd);
    }
    ~User() {
        if (name != nullptr) delete[] name;
        if (passwd != nullptr) delete[] passwd;
    }

    void printUser() const {
        std::cout << id << ". " << name << '\n';
    }
    bool verifyPasswd(const char* pass) {
        return strcmp(pass, passwd) == 0;
    }
};

int User::nextId = 1;

void authUser(User user) {
    std::cout << "Enter password: ";
    char buffer[256];
    std::cin.getline(buffer, 256);
    if (user.verifyPasswd(buffer))
    {
        std::cout << "Login was successfull!" << '\n';
    }
    else {
        std::cout << "Wrong password.\n";
    }
}

int main()
{
    User u1("qwerty", "1234");

    authUser(u1);

    User copy = u1;

    //std::cout << User::nextId << '\n';
    //User u2("asdf");
    //std::cout << User::nextId << '\n';

    //std::cout << User::getNextId() << '\n';
    ////std::cout << u1.getNextId() << '\n';

    //u1.printUser();
    //u2.printUser();
}