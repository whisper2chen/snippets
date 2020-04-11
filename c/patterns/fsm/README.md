基于状态跳转表
(一般可以X表示状态，Y轴表示对应发生的事件，相关值表示需要切换到的状态)
优点：可以基于表格提前预设好状态跳转表 程序逻辑部分可以最小化改动
缺点：只是基于状态切换 如果需要定制切换状态时调用相关函数则不方便处理


基于STATE PATTERN
1.将状态行为抽象出来作为接口(在C语言中可以使用strcut来包含一系列函数指针来表示接口)
2.具体的状态作为对象实现所关心的状态切换函数
3.以一个状态接口的值作为上下文保存当前状态，当状态切换时 切换对应的实现接口
