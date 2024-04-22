#include <iostream>
#include <string>

using namespace std;

class Pet {
protected:
    string name;
public:
    Pet(const string& name) : name(name) {}

    string getName() const { return name; }

    virtual void introduce() const {
        cout << "I am a pet named " << name << endl;
    }
};

class Dog : virtual public Pet {
private:
    string breed;
public:
    Dog(const string& name, const string& breed) : Pet(name), breed(breed) {}

    void introduce() const override {
        cout << "I am a dog named " << name << ", my breed is " << breed << endl;
    }
};

class Cat : virtual public Pet {
private:
    string color;
public:
    Cat(const string& name, const string& color) : Pet(name), color(color) {}

    void introduce() const override {
        cout << "I am a cat named " << name << ", my color is " << color << endl;
    }
};

class Parrot : virtual public Pet {
private:
    string featherColor;
public:
    Parrot(const string& name, const string& featherColor) : Pet(name), featherColor(featherColor) {}

    void introduce() const override {
        cout << "I am a parrot named " << name << ", my feather color is " << featherColor << endl;
    }
};

int main() {
    Pet* pet1 = new Dog("Buddy", "Labrador");
    Pet* pet2 = new Cat("Pushok", "White");
    Pet* pet3 = new Parrot("Polly", "Green");

    pet1->introduce();
    pet2->introduce();
    pet3->introduce();

    delete pet1;
    delete pet2;
    delete pet3;

    return 0;
}