#include <iostream>

class Animal {
public:
    virtual void makeSound() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "왈!" << std::endl;
    }
    ~Dog() override {}
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "야옹!" << std::endl;
    }
    ~Cat() override {}
};

class Cow : public Animal {
public:
    void makeSound() const override {
        std::cout << "음머!" << std::endl;
    }
    ~Cow() override {}
};

int main() {
    Animal* farm[3];

    Dog Dog;
    Cat Cat;
    Cow Cow;

    farm[0] = &Dog;
    farm[1] = &Cat;
    farm[2] = &Cow;

    std::cout << "--- 시작 ---" << std::endl;

    for (int i = 0; i < 3; ++i) {
        farm[i]->makeSound();
    }

    std::cout << "--- 완료 ---" << std::endl;

    return 0;
}