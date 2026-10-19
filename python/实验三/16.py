import json

data = {
    "姓名":"张三",
    "年龄":20,
    "爱好":["看书","打球"]
}

with open("data.json","w",encoding="utf‑8") as fp:
    json.dump(data, fp, ensure_ascii=False, indent=4)

with open("data.json","r",encoding="utf‑8") as fp:
    obj = json.load(fp)

print("读取得到Python对象：", obj)
print(f"类型：{type(obj)}")

json_str = json.dumps(obj, ensure_ascii=False, indent=4)
print("\n格式化json字符串输出：")
print(json_str)