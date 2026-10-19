def shoptotal(shopping_list):
    total = 0
    for item in shopping_list:
        name,price,num = item
        total = total + price * num
    return total

buy = [["榴莲",150,2],["火龙果",15,1]]
print(shoptotal(buy))