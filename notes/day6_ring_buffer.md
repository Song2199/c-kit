# Day 6 Ring Buffer

## 1. read和write

read表示：下一次要读取的位置

write表示：下一次要写入的位置

## 2. push操作

写入位置：当前write所在位置

写入后移动谁：移动write指向下一个要写入的位置 

## 3. pop操作

读取位置：当前read所在位置

读取后移动谁：read 移向下一次要读取的位置

## 4. 下标绕回

容量为5时，有效下标：0，1，2，3，4

下标4的下一个位置：0

使用的计算方式：(write + 1) %5 

## 5. 空条件

判断公式：write==read

为什么：push 后数据数量：增加 1

pop 后数据数量：减少 1  
数据读完时：read == write，缓冲区为空

## 6. 满条件

判断公式：(write + 1) % capacity == read

为什么需要留一个空格：防止出现全满和全空出现相同状态

容量为5时最多保存：4个有效元素

## 7. 异常操作

空时继续pop：拒绝读取

满时继续push：无法写入

## 8. 手动模拟

操作顺序：

push(A) → push(B) → push(C) → pop() → push(D) → push(E)

最终read：1

最终write：0

有效数据及读取顺序：B → C → D → E 

## 9. 今天最容易混淆的地方

我第一次错误认为：满状态的时候是 write ==read (满状态的时候是write追上read)满状态时还能继续push，以为read write是读取和写入当前数据

经过推导后我理解：满状态时应该是 (write +1)%capacity==read,满状态之后会拒绝写入， read和write是指向下一个要读取和写入的位置 