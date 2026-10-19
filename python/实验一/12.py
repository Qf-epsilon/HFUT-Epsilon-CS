'''商店需要找钱给顾客，现在只有 50 元，5 元和 1 元的人民币若干张。输
入一个整数金额值，给出找钱的方案，假设人民币足够多，且优先使用面额大的
钱币。'''
money=int(input("请输入找钱金额："))
num_50=money//50
money=money % 50
num_5 = money // 5
money = money % 5
num_1 = money
print(f"找钱：50元 {num_50} 张，5元 {num_5} 张，1元 {num_1} 张")