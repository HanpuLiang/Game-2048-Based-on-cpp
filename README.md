# Game-2048-Based-on-cpp

在知乎上偶尔看到有人利用写这种小程序练手，正好最近刚考完期末考试，所以就花了一个晚上写了一下，也简单的写了一个2048.

之前没有用c++写过比较大型的内容，对c++的理解也不是很深。所以经过这一次编写，对游戏算法的理解以及c++多文件之间的调用有了更深刻的理解。

在写之前，我先简单的构思了以下整个游戏会分成哪几个部分，私以为可以简单的分为六个部分:

1. 初始化游戏地图
2. 在游戏地图内格子随机生成一个数字
3. 在屏幕上显示出地图
4. 玩家输入操控指令
5. 程序对玩家的指令进行相应移动与合并
6. 判断游戏是否结束，若没有结束就跳到2，否则跳出

我发现这六点当中，只有第5点最有难度，也就是如何去移动整个表盘中的元素，如何判别是否可以合并，四个方向上的移动合并有什么共同点和差别，如何合并等内容。其他5点就很简单了，基本上没有这么复杂的逻辑。
