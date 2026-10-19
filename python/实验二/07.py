seat = input().strip()

row = seat[:-1]
letter = seat[-1].upper()

if row.isdigit() and 1 <= int(row) <= 17 and letter in ["A", "B", "C", "D", "F"]:
    if letter == "A" or letter == "F":
        print("窗口")
    elif letter == "C" or letter == "D":
        print("过道")
    elif letter == "B":
        print("中间")
else:
    print("座位号不存在")