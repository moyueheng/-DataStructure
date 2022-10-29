#include <stdio.h>

class Animal
{
private:
public:
    virtual void speak()
    {
        printf("动物在说话\n");
    };
};

class Cat : public Animal
{
public:
    virtual void speak() // 子类的virtual可写可不写
    {
        printf("猫在说话\n");
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        printf("狗在说话\n");
    }
};

// 执行地址
// 地址早绑定，在编译阶段确定函数地址，不管我传猫传狗都是“动物在说话”
// 如果我们想我们传什么就是什么在说话，我们需要在运行阶段进行帮顶，也就是地址晚绑定、

// 动态多态满足条件
// 1.有继承关系
// 2.子类重写父类的虚函数

// 动态多态的使用
//  父类的指针或者引用，执行子类对象
void doSpeak(Animal *a)
{
    a->speak();
}

int main(int argc, char const *argv[])
{
    Cat *cat = new Cat();
    doSpeak(cat);
    return 0;
}
