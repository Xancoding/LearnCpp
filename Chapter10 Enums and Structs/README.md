# Demand
1. 声明一个代表你的怪物的结构
2. 怪物的类型（为此使用枚举类）应该可以是以下之一：an ogre, a dragon, an orc, a giant spider, or a slime
3. 每个单独的怪物还应该有一个名字（使用 `std::string` 或 `std::string_view`），以及代表它们在死前可以承受多少伤害的生命值
4. 编写一个名为 printMonster() 的函数，打印出该结构的所有成员
5. 实例化食人魔和史莱姆，使用初始化列表初始化它们，并将它们传递给 printMonster()
6. 您的程序应产生以下输出：
```
This Ogre is named Torg and has 145 health.
This Slime is named Blurp and has 23 health.
```
