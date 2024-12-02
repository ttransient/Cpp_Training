// 第一次实验
定义了Executor类，实现了L,R,M指令的执行，以及对象初始化，并通过枚举方向来定义小车朝向。
SampleTest1实现了对小车类的几个基本指令的测试

//第二次实验
增加了F指令，即加速指令，在此基础上，修改了L,R,M等指令的执行，并相应增添和修改了测试代码。

//第3次实验，增加了B指令,并实现了相应命令功能的修改。还对代码做了两处优化。一是对部分类内函数使用了noexcept关键字声明，优化代码，帮助编译器进行更好的优化，进一步提高了程序的整体性能，二是利用表驱动，哈希表结合lambda匿名函数，将原本繁琐的switch，case语句，替换成了更简洁清晰的表达
