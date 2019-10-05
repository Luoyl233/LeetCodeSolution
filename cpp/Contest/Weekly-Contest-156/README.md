## Weekly-Contest-156



#### Q1 [Unique Number of Occurrences](https://leetcode.com/contest/weekly-contest-156/problems/unique-number-of-occurrences)



1. 遍历数组，计算每个元素的出现次数，保存到map中；

2. 然后遍历map，把出现次数加入集合set中，若set出现相同元素，则有不同元素出现了相同次数。



#### Q2 [Get Equal Substrings Within Budget](https://leetcode.com/contest/weekly-contest-156/problems/get-equal-substrings-within-budget)



1. 计算两个字符串每个位置字符转换的代价，保存到数组costs中（这一步不是必须的，也可以在第二步时一遍遍历一边计算costs）；

2. 从左往右遍历costs，维持一个**滑动窗口**，窗口内元素和不大于maxCost（首先往右扩展窗口，加入当前元素，然后从左边开始收缩）；
3. 遍历的同时记录窗口的最大长度ans，遍历结束，ans即为满足要求的最大长度。



#### Q3 [Remove All Adjacent Duplicates in String II](https://leetcode.com/contest/weekly-contest-156/problems/remove-all-adjacent-duplicates-in-string-ii)



1. 从左往右遍历，把暂时未被删除的字母（连续相同字母个数小于k)放入栈**stack**里；
2. 扫描每个字母时，都先往栈里看看，栈顶是否是相同元素且个数是否大于大于k；
3. 最后stack里剩下的字母即为最终结果。



小技巧：初始时先往stack里放入一个**dummy entry**，减少栈空情况的判断；



#### Q4 [Minimum Moves to Reach Target with Rotations](https://leetcode.com/contest/weekly-contest-156/problems/minimum-moves-to-reach-target-with-rotations)



穿过迷宫的加强版，对象占两个格子，不仅有障碍，另外增加了旋转操作，因此需要判断的情况更复杂。

解决方案：BFS或者DP。



###### 二维DP：

1. 根据依赖关系分析，二维DP理论上可以优化为一维DP；

2. 因为蛇可以旋转，需要两个DP数组H和V，分别表示蛇水平和竖直两种状态；
3. 注意状态转移方程里，H和V之间也会相互转化，但需要判断旋转过程涉及的四个格子是否存在障碍物；