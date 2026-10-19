str = input("请输入一段字符串：")
upper_num = 0
lower_num = 0
digit_num = 0
other_num = 0

for ch in str:
    if ch.isupper():
        upper_num += 1
    elif ch.islower():
        lower_num += 1
    elif ch.isdigit():
        digit_num += 1
    else:
        other_num += 1

print(f"大写字母：{upper_num}")
print(f"小写字母：{lower_num}")
print(f"数字：{digit_num}")
print(f"其他符号：{other_num}")