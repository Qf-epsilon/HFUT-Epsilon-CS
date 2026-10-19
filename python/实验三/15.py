with open("test.txt", "r", encoding="utf-8") as f:
  content_read = f.read()
  print("--- read() 结果 ---")
  print(content_read)

with open("test.txt", "r", encoding="utf-8") as f:
  print("--- readline() 结果 ---")
  while True:
    line = f.readline()
    if not line:
      break
    print(line, end="")

with open("test.txt", "r", encoding="utf-8") as f:
  lines = f.readlines()
  print("\n--- readlines() 结果 ---")
  print(lines)