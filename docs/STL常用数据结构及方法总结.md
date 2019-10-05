## 线性表



下面的速查表中， v表示值，it表示迭代器， i表示下标。



|        | 插入                        | 删除                    |   访问    | 表头      | 表尾   |
| :----: | :-------------------------- | ----------------------- | :-------: | --------- | ------ |
| vector | push_back(v),               | pop_back()              | [], at(i) | front()   | back() |
|  list  | push_back(v), push_front(v) | pop_back(), pop_back()  |           | front()   | back() |
| stack  | push(v)                     | pop()                   |           | **top()** |        |
| queue  | push(v)                     | pop()                   |           | front()   | back() |
| deque  | push_front(v), push_back(v) | pop_front(), pop_back() | [], at(i) | front()   | back() |
| string | push_back(c), +=            | pop_back(), replace     | [], at(i) | front()   | back() |



##### string



| 方法                       | 功能                                      |
| -------------------------- | ----------------------------------------- |
| c_str()                    | 返回字符串的**不可修改**的 C 字符数组版本 |
| replace(pos, cnt, str)     | 替换字符串的指定部分                      |
| substr(pos, cnt)           | 返回子串                                  |
| find(str, pos)             | 于字符串中寻找字符                        |
| stoi(str), stol(), stoll() |                                           |
| stoul(), stoull            |                                           |
| stof(), stod(), stold()    |                                           |
| to_string(*)               |                                           |





## 非线性表



|                | 插入      | 删除      | 访问                                 |
| -------------- | --------- | --------- | ------------------------------------ |
| unordered_/map | []        | erase(it) | find(k), count(k), contains(k),  [k] |
| unordered_/set | insert(v) | erase(it) | find(), count(), contains()          |
| bitset         |           |           | []                                   |



##### bitset



| 方法             | 功能                       |
| :--------------- | -------------------------- |
| &=,=, ^=, ~      | 进行二进制与、或、异或及非 |
| <<=, >>=, <<, >> | 进行二进制左移和右移       |
| set()            | 全置为true                 |
| reset()          | 全置为false                |
| flip()           | 翻转所有位                 |















