//姓名：廖治政

//学号：2023060904003

// 第一次实验
定义了Executor类，实现了L,R,M指令的执行，以及对象初始化，并通过枚举方向来定义小车朝向。
SampleTest1实现了对小车类的几个基本指令的测试

//第二次实验
增加了F指令，即加速指令，在此基础上，修改了L,R,M等指令的执行，并相应增添和修改了测试代码。

//第3次实验，增加了B指令,并实现了相应命令功能的修改。还对代码做了两处优化。一是对部分类内函数使用了noexcept关键字声明，优化代码，帮助编译器进行更好的优化，进一步提高了程序的整体性能，二是利用表驱动，哈希表结合lambda匿名函数，将原本繁琐的switch，case语句，替换成了更简洁清晰的表达。

//第三次实验，发现类函数命名有些不符合规则，于是做了统一修改

//第四次实验，增加了TurnRound指令，并添加了相应的测试文件。针对之前的表驱动做了进一步优化，将哈希表作为一个成员变量，避免重复开辟哈希表带来的消耗

//作业，增加了Executor的两个子类，一个Bus类，一个跑车类(Runcar)，并 重写了与父类不同的相关指令，同时新增了命名空间adas，对代码进行了优化，避免了命名冲突，增加了代码的可读性和可维护性。

//更新，对整体框架进行了修改，处理了之前代码文件分散的问题，将cpp文件hpp文件以及test文件分别放在不同文件夹下，便于阅读和管理，同时新使用了cmake进行编译
