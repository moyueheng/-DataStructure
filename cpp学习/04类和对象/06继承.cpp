
#include <stdio.h>

class Animal 
{
public:
    int age; // 随机值
};

class Sheep : virtual public Animal
{
};

class Tuo : virtual public Animal
{
};

class SheepTuo : public Sheep, public Tuo
{ // 直接计算当前的继承的上面有多大
};

int main(int argc, char const *argv[])
{
    SheepTuo st = SheepTuo();
    printf("%d\n", sizeof(st)); // 这样的继承 8, 虚继承24，因为多了两个虚基类指针，在64位操作系统中指针的大小为8个字节
    // 这个age就产生的歧义, 到底我的羊驼是多少岁？
    st.Tuo::age = 10;
    st.Sheep::age = 100;
    // 这个菱形继承可以通过虚继承来解决, 虚继承之后Animal称为虚基类
    printf("%ld\n", st.age);
    printf("%ld\n", st.Sheep::age);
    printf("%ld\n", st.Tuo::age);
    return 0;
}
