# Demand
1. 要求用户输入 2 个数字，第一个是要开始的数字的平方根，第二个是要生成的数字的数量。生成一个从 2 到 4 的随机整数，以及用户选择范围内的平方数。将每个平方数乘以随机数。您可以假设用户输入了有效数字。
2. 用户必须计算生成了哪些数字。该程序检查用户是否猜对并从列表中删除猜中的数字。如果用户猜错了，游戏就结束了，程序会打印出最接近用户最终猜测的数字，但前提是最终猜测的差距不超过 4。
```
Start where? 4
How many? 8
I generated 8 square numbers. Do you know what each number is after multiplying it by 2?
> 32
Nice! 7 number(s) left.
> 72
Nice! 6 number(s) left.
> 50
Nice! 5 number(s) left.
> 126
126 is wrong! Try 128 next time.
```
```
Start where? 1
How many? 3
I generated 3 square numbers. Do you know what each number is after multiplying it by 4?
> 4
Nice! 2 numbers left.
> 16
Nice! 1 numbers left.
> 36
Nice! You found all numbers, good job!
```
3. 使用 `std::find`在列表中搜索数字
4. 使用 `std::vector::erase` 删除元素
5. 使用 `std::min_element` 和 `lambda` 来找到最接近用户猜测的数字
6. 使用 `<cmath>` 中的 `std::abs` 来计算两个数字之间的差值