ip = input().strip()
parts = ip.split(".")

if len(parts) != 4:
    print("No")
else:
    flag = True
    for part in parts:
        if not part.isdigit():
            flag = False
            break
        num = int(part)
        if num < 0 or num > 255:
            flag = False
            break

    if flag:
        print("Yes")
    else:
        print("No")