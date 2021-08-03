#include <iostream>
#include <string>
#include <ctime>
using namespace std;




/*Перегрузка функций*/
int Sum(int a, int b) {

    return a + b;
}

double Sum(double a, double b) {

    return a + b;
}

double Sum(int a, int b, int c) {

    return a + b + c;
}








class Human {
public:
    int age;
    int weight;
    string name;

    void Print() {
        cout << "Имя: " << name << "\nВес: " << weight << "\nВозраст: " << age << endl;
    }

};

// По умолчанию модификатор доступа - private
// private не доступно из вне, но доступно для дружественных классов
class Point {
  
private:
    int x;
    int y;
    void PrintY() {

        cout << "Y is " << y << endl;
    }


public:

    
    // Конструктор - начальное значение переменной 
    // Если не написать конструктор, он реализуется по умолчанию
    Point(int valueX, int valueY) {
        x = valueX;
        y = valueY;
        

    }
    // Напишем 2 конструктора для перегрузки
    

    Point() {

        x = 0;
        y = 0;

    }
   
    // Геттеры и сеттеры
    int GetX() {

        return x;
    }

    void SetX(int x) {
        // this указывает на задаваемый объект
        this->x = x;

    }


    int GetY() {

        return y;
    }

    void SetY(int valueY) {
        y = valueY;

    }
    
    void Print() {
        cout << "x= " << x << "\ny=" << y << endl;
        PrintY();
        cout <<"this returns "<<this << endl;

    }

    // перегрузка оператора сложения
    Point operator +(Point& other) {


        this->x = this->x + other.x;
        this->y = this->y + other.y;

        return *this;
    }

    // перегрузка оператора инкримента
   Point  &operator ++() {


       this->x ++;
       this->y ++;

        return *this;
    }


   // Дружественная функция имеет доступ к полям private
   friend void ChangeX(Point& value);

};



class CoffeeGrinder {
/*Смоделируем аботу кофемашины*/
private:
    bool CheckVoltage() {
        if (rand() % 2 == 1)
            return true;
        else
            return false;

    }


public:
    void Start() {
        if (CheckVoltage()) {
            cout << "Кофе перемолот!" << endl;
        }
        else
            cout << "Напряжение не подходит для работы кофемолки" << endl;
    }



};



// Демонстрация работы деструктора
class MyClass {
    int data;
public:
    MyClass(int data)
    {
        this->data = data;
        cout <<" Объект "<<data<< " Вызвали конструктор" << endl;
    }

    MyClass(const MyClass& other) {
        // конструктор копирования
        this->data = other.data;
        
    }

    // перегрузка оператора присваивания
    MyClass &operator = (const MyClass& other) {
        this->data = other.data;
        return *this;
    }

    // перегрузка оператора сравнения
    bool operator ==(const MyClass& other) {

        return this->data == other.data;

    }

    ~MyClass() {
        cout << "Вызвался деструктор.Не может содержать парпаметры. Уничтожен "<<data<< endl;
    }



};



// Конструктор копирования
void Foo(MyClass value) {

    cout << "Вызвалась функция Foo" << endl;
}






MyClass Foo2()
{
    cout << "Вызвалась функция Foo2 " << endl;
    MyClass temp(2);

    return temp;
}


// Перегрузка оператора индексирования

class IndexClass 
{
public:

    int &operator[](int index) {

        return arr[index];
    }

private:
    int arr[5]{ 8,10,12,14,16 };
    


};


void ChangeX(Point &value) {
    value.x = 100;




}


/* Дружественные методы класса*/





class Man;
class Apple;

class Man {

public:
    void TakeApple(Apple& apple); 


    
};







class Apple {
    friend Man;
    
public:
    //static int is the same for every object
    
    Apple(int weight, string color) {
        this->weight = weight;
        this->color = color;
        Count++;
        Id = Count;
    }


    int GetId() {

        return Id;
    }

    static int GetCount() {
        return Count;
    }


    static void ChangeColor(Apple &apple, string color) {
        apple.color = color;




    }


   string  GetColor() {

        return color;
    }

private:
    static int Count;
    int weight;
    string color;
    //friend void Man::TakeApple(Apple& apple);(дружественная функция через класс)
    // Создадим Id
    int Id; 

};

int Apple::Count = 0;




/*Вложенные классы*/

class Image
{

public:

    void GetImageInfo() {
        for (int i = 0; i < LENGTH; i++) {

            cout << pixels[i].GetInfo();
            cout << endl;



        }






    }



    class Pixel
    {


    public:
        Pixel(int r, int g, int b) {
            this->r = r;
            this->g = g;
            this->b = b;

        }

        string GetInfo() {

            return "Red " + to_string(r) + " Green " + to_string(g) + " Blue " + to_string(b);
        }

    private:
        int r;
        int g;
        int b;



    };
private:
    static const int LENGTH = 5;
    Pixel pixels[LENGTH]
    {
        Pixel(0,4,64),
        Pixel(0,5,54),
        Pixel(0,7,24),
        Pixel(9,7,4),
        Pixel(0,0,64)
    };


};


// Агрегация и композиция(один класс вложен в другой с возможностью использовать его в других местах или без



class Cap {
    // агригация
public:

    string GetColor() {
        return color;
    }


private:
    string color = "red";


};




class Person {

public:
    // композиция
    void Think() {
        brain.Think();

    }



    void inspect_the_cap() {


        cout << "Цвет моей кепки:" << cap.GetColor();
    }

private:
    class Brain {
    public:
        void Think() {

            cout << "Я думаю" << endl;
        }


    };

    Brain brain;
    Cap cap;
};



/*Inheritance*/


class PersonInUniversity
{
private:
    string name = "Ivan Ivanov";
public:
    string GetName() {
        return name;
    }

};


class Student : public PersonInUniversity
{
public:
    string group;



};



class Professor : public PersonInUniversity
{

public:
    string subject;

};


class ExternalStudent : public Student
{
public:
    void Learn() {

        cout << "Я хожу в вуз реже обычного студента" << endl;
    }


};

/*Вертуальные функции*/

class Gun
{
public:
    
    virtual void shoot() {
        cout<<"Bang!"<<endl;
    }


};


class SubMachineGun : public Gun
{
    // переопределение
public:
    void shoot() 
    {

        cout << "Bang! Bang! Bang!" << endl;
    }



};

// Класс состоящий из чисто вертуальных функций(функций без реалитзации - абстрактный класс)
// Экземпляр абстрактного класса невозможно создать

class Weapon
{
public:
    virtual void shoot() = 0;

};

class Knife : public Weapon
{
public:
    void shoot() {

        cout << "STAB!" << endl;
    }

};

// Конструкция enum
// Опишем состояние работы компьютера

class PC
{


public:
    enum PCState
    {
        OFF,
        On,
        SLEEP


    };

    PCState GetState() {
        return State;
    }

    void SetState(int input) {
        if (input == 0) {
            this->State = OFF;
        }
    }

private:
    PCState State;



};




int main()
{
    cout << "Input 1 to see:" << endl;
    cout << "Constructor, destructor, incapsulation and (this)" << endl;
    cout << "Input 2 to see:" << endl;
    cout << "Overloading" << endl;
    cout << "Input 3 to see:" << endl;
    cout << "Friendly methods" << endl;
    cout << "Input 4 to see:" << endl;
    cout << "Inheritance" << endl;



    int key_int;
    cin >> key_int;
    if (key_int == 1) {

        srand(time(0)); // генерация рандомных чисел
        setlocale(LC_ALL, "russian");
        cout << "Class Human" << endl;
        Human firstHuman;
        firstHuman.age = 30;
        firstHuman.weight = 100;
        firstHuman.name = "Ivanov Ivan Ivanovich";
        firstHuman.Print();
        cout << "____________________________________________" << endl;

        cout << "Class Point" << endl;
        Point a;
        a.SetX(10);
        cout << "Getter для х возвращает:" << a.GetX() << endl;
        a.Print();

        Point c(60, 70);
        c.Print();
        cout << "____________________________________________" << endl;


        cout << "Class CoffeeGrinder" << endl;
        CoffeeGrinder b;
        b.Start();

        cout << "___________________________________________________" << endl;
        cout << "Перегрузка функции sum " << endl;
        cout << Sum(4, 5) << endl;
        cout << Sum(4.1, 5.2) << endl;
        cout << Sum(5, 4, 6) << endl;



        // деструктор вызывается в обратном порядке
        MyClass FirstClass(5);
        MyClass SecondClass(6);


        // деструктор вызывается 2 раза. Двойное отчищение одного участка памяти может привести к ошибке
        Foo(FirstClass);

        Foo2();
        //Скопируем класс
        MyClass ThirdClass(FirstClass);

        // реализуем конструктор копирования в классе MyClass

    }
    else if (key_int == 2) {
        setlocale(LC_ALL, "russian");
        // Перегрузка операторов
        MyClass Overloading_class_1(7);
        MyClass Overloading_class_2(11);
        // Перегрузка оператора присвоения
        cout << "Перегрузка оператора присваивания" << endl;
        Overloading_class_2 = Overloading_class_1;
        // Перегрузка оператора сравнения
        cout << "Перегрузка оператора сравнения" << endl;
        bool equality;
        equality = Overloading_class_2 == Overloading_class_1;
        cout<< equality << endl;



        Point a(2, 3);
        Point b(3, 2);
        // Перегрузка оператора сложения
        cout << "Перегрузка оператора сложения" << endl;
        Point c = a + b;

        c.Print();
        // Перегрузка оператора инкриментирования
        cout << "Перегрузка оператора инкриментирования" << endl;
        ++c;
        c.Print();

        // Перегрузка оператора индексирования
        cout << "Перегрузка оператора индексирования" << endl;
        IndexClass mass;
        cout << mass[3] <<endl;
        // Использование дружественной функции
        ChangeX(c);
        cout << "Использование дружественной функции" << endl;
        c.Print();


    }
    else if (key_int == 3) {
        setlocale(LC_ALL, "russian");
        Apple apple(100, "red");
        Apple apple1(100, "red");
        Apple apple2(100, "red");
        Man man;
        man.TakeApple(apple);
        
        cout << "Генератор Id" << endl;
        cout << apple.GetId() << endl;
        cout << apple1.GetId() << endl;
        cout << apple2.GetId() << endl;
        // Вызов статического метода через обращение к классу
        cout << "Яблок: " << Apple::GetCount() << endl;


        Apple::ChangeColor(apple,"blue");
        cout << "Color of 1 apple is " << apple.GetColor() << endl;



        Image Img;
        Img.GetImageInfo();

        // Обратимся к классу через вложенный
        Image::Pixel graphic(0, 62, 62);
        cout << graphic.GetInfo() << endl;




        // композиция
        cout << "Пример композиции" << endl;
        Person person;
        person.Think();

        cout << "Пример Агрегации" << endl;
        person.inspect_the_cap();


    }

    else if (key_int == 4) {
    setlocale(LC_ALL, "russian");
    ExternalStudent ExtraSt;
    cout << "Name is " << ExtraSt.GetName() << endl;
    ExtraSt.Learn();

    cout << "Работа вертуальных функций" << endl;
    Gun gun;
    SubMachineGun submachinegun;
    gun.shoot();
    submachinegun.shoot();
    Knife knife;
    knife.shoot();

    PC pc;

    pc.SetState(0);

    cout << "Конструкция enum" << endl;
    switch (pc.GetState())
    {
    case pc.PCState::OFF:
        cout << "Выключен" << endl;





    }



}


    return 0;
}

void Man::TakeApple(Apple& apple) {

    cout << "TakeApple " << " Weight: " << apple.weight << " color =  " << apple.color << endl;

}

