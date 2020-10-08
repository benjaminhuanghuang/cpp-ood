# Automated Teller Machine (ATM)

https://careercup.com/question?id=5747801813155840

http://www.cs.nuim.ie/~dkelly/CS100-2/Virtual%20Bank.htm

1.Clarify
ATM机的Input和Output是什么?
Assumption: Input 是卡, output 是现金

Input 有什么限制吗?
Assumption: 只能是debit card

output 有什么限制吗?
Assumption: 只能是20美元的倍数

AOutput 会不足吗?
Assumption: ATM永远有足够的余额 (Bonus: 这里可以考虑如果不够的话应该怎么处理)

Input 有什么特点?
Assumption: 一张卡可能有多个账户 (Bonus: 这个不太容易想到， 没想到也没关系，我们可以先按照一个account来做)

2.Core objects
Debit Card

ATM Machine

Account

3.Use cases
Take debit card

Authorization / Log in

(Optional - 如果一张卡能有多个account就需要这个) Select account

Check balance

Deposite money

Withdraw money

Log out

4.Classes
ATM Machine
float balance (Optional - 如果ATM机余额有限制就需要这个)

Session currentSession ( Tips : 如果一个主体，它的操作<比如check balance / deposite / withdraw>是针对每一个用户的， 那么经常会考虑到加入Session这个Class。实践中如果碰到需要login/logout的主体，经常会用到Session)

void takeDebitCard (DebitCard card)

List login (String passcode)

void selectAccount (Account account)

float checkBalance ()

void depositeMoney (float amount)

float withDrawMoney (float amount)

void logOut ()

Session
DebitCard currentDebitCard

Account currentAccount

Account
float balance

void depositeMoney (float amount)

withDrawMoney (float amount)

5.Correctness
增加各式的Exceptions

对于ATM机，有许多种Design pattern可以适用，其中比较合适的就有我们《OOD面向对象专题》课上讲过的State Design Pattern, 大家可以自己思考有哪些合适的states。

6.总结
ATM Machine作为一道real life object的题目，做法和我们上课讲过的解法大同小异，其中值得注意的三点分别是对Session的使用;可能出现各式各样的Exception; 以及一张卡对应多个 Account的business logic。