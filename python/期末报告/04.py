weight = float(input("输入快递重量(单位为千克）："))
if weight <= 1:
    fees = 10
else:
    fees = 10 + (weight - 1)*3
print(f"应该支付的邮费为：",fees)