## [Weekly Contest 159](https://leetcode.com/contest/weekly-contest-159)



### [1232. Check If It Is a Straight Line](https://leetcode.com/contest/weekly-contest-159/problems/check-if-it-is-a-straight-line)



##### Description

>You are given an array `coordinates`, `coordinates[i] = [x, y]`, where `[x, y]` represents the coordinate of a point. Check if these points make a straight line in the XY plane.



##### Solution

**斜率相等**！但**不要直接算出斜率**，这样要考虑特殊情况(斜率为0或者无穷)。假设k1 = dy1 / dx1，k2 = dy2 / dx2，我们只需要判断dy1 * dx2 是否等于 dy2 * dx1。





###  [1233. Remove Sub-Folders from the Filesystem](https://leetcode.com/contest/weekly-contest-159/problems/remove-sub-folders-from-the-filesystem)



##### Description

>Given a list of folders, remove all sub-folders in those folders and return in **any order** the folders after removing.
>
>If a `folder[i]` is located within another `folder[j]`, it is called a sub-folder of it.
>
>The format of a path is one or more concatenated strings of the form: `/` followed by one or more lowercase English letters. For example, `/leetcode` and `/leetcode/problems` are valid paths while an empty string and `/` are not.



##### Solution

1. 我的做法：类似于字典树(Trie)的构造过程，不同的地方有两个，一是每个节点从Trie中的一个字母变为一个文件名，比如“/a”是其中的一个节点；二是插入新的folder时，从根节点往下搜索插入时，如果中间节点出现了完整的folder路径，则终止插入。时间复杂度O(nd)，d为树最大深度。
2. 大佬的做法：排序 + 遍历一遍(因为排序后，上层文件夹一定在子目录前面)。时间复杂度O(nlogn)。比我的快多了(64 ms vs 228 ms)。



##### 总结

看到题目里的加粗的字了吗？疯狂暗示你排序！排序！排序！





### [1234. Replace the Substring for Balanced String](https://leetcode.com/contest/weekly-contest-159/problems/replace-the-substring-for-balanced-string)



##### Description

>You are given a string containing only 4 kinds of characters `'Q',` `'W', 'E'` and `'R'`.
>
>A string is said to be **balanced** if each of its characters appears `n/4` times where `n` is the length of the string.
>
>Return the minimum length of the substring that can be replaced with **any** other string of the same length to make the original string `s` **balanced**.
>
>Return 0 if the string is already **balanced**.



##### Solution

1. 我的做法：
    	1. 遍历一遍，统计不同字母个数；
    	2. 计算出哪些字母超过了1/4；
    	3. 滑动窗口寻找包含超出字母的最短字符串，即问题 [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring)

2. 更好的做法：同样滑动窗口，实现有差异，滑动窗口里是被**排除**的字符。



### [1235. Maximum Profit in Job Scheduling](https://leetcode.com/contest/weekly-contest-159/problems/maximum-profit-in-job-scheduling)



##### Description

>We have `n` jobs, where every job is scheduled to be done from `startTime[i]` to `endTime[i]`, obtaining a profit of `profit[i]`.
>
>You're given the `startTime` , `endTime` and `profit` arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.
>
>If you choose a job that ends at time `X` you will be able to start another job that starts at time `X`.

>
>
>**Constraints:**
>
>- `1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4`
>- `1 <= startTime[i] < endTime[i] <= 10^9`
>- `1 <= profit[i] <= 10^4`



##### Solution

DP！！！



##### 总结

- 仔细看Constraints，`1 <= startTime[i] < endTime[i] <= 10^9`，因此按照最大时间设置DP数组来进行DP是很可能时间超限的！
- 需要对(s, e, p)三元组按照s排序，先把它们放入一个N行3列数组中。
- lower_bound/upper_bound函数里面，因为要搜索的元素以及是T&类型的引用，如果在自定义的comp函数里把lambda函数参数定义为引用，会报错！