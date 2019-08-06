# 三种方式实现词频统计
- map和unordered_map基于hash映射,底层用红黑树实现，统计速度极快
- vector的统计速度相比较而言就弱了很多
此处保留的统计结果基于unordered_map实现。