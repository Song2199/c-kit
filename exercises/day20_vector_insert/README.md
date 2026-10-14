目标：
实现 int_vector_insert()

功能：
在指定index插入元素

设计：
设计:
1. 检查 vector 是否为空
2. 检查 index <= size
3. 判断是否需要扩容
4. 从后往前移动元素
5. 写入新元素
6. size++

失败:
return 0
状态保持不变

成功:
return 1

## Day21

新增 Vector API:

- vector_destroy()
  - 释放动态内存
  - 重置状态

- vector_get()
  - 安全读取元素
  - 越界返回失败

- vector_set()
  - 修改已有元素
  - 不支持插入新元素