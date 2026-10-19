import json

class Book:
    def __init__(self,isbn,name,author,stock):
        self.isbn = isbn
        self.name = name
        self.author = author
        self.stock = stock

    def borrow(self):
        if self.stock > 0:
            self.stock -=1
            return True
        return False

    def give_back(self):
        self.stock +=1

    def show_info(self):
        print(f"ISBN:{self.isbn},书名:{self.name},作者:{self.author},库存:{self.stock}")

class Library:
    def __init__(self):
        self.book_list = []

    def add_book(self,book):
        self.book_list.append(book)

    def del_book(self,isbn):
        for b in self.book_list:
            if b.isbn == isbn:
                self.book_list.remove(b)
                return True
        return False

    def query_by_name(self,name):
        res = []
        for b in self.book_list:
            if name in b.name:
                res.append(b)
        return res

    def borrow_book(self,isbn):
        for b in self.book_list:
            if b.isbn == isbn:
                if b.borrow():
                    print("借阅成功")
                else:
                    print("库存不足")
                return
        print("未找到该书")

    def return_book(self,isbn):
        for b in self.book_list:
            if b.isbn == isbn:
                b.give_back()
                print("归还成功")
                return
        print("未找到该书")

    def show_all(self):
        for b in self.book_list:
            b.show_info()

    def save_json(self):
        data = []
        for b in self.book_list:
            d = {"isbn":b.isbn,"name":b.name,"author":b.author,"stock":b.stock}
            data.append(d)
        with open("lib.json","w",encoding="utf-8") as f:
            json.dump(data,f,ensure_ascii=False,indent=2)

    def load_json(self):
        try:
            with open("lib.json","r",encoding="utf-8") as f:
                data = json.load(f)
            for item in data:
                bk = Book(item["isbn"],item["name"],item["author"],item["stock"])
                self.book_list.append(bk)
        except:
            pass

if __name__ == "__main__":
    lib = Library()
    lib.load_json()
    while True:
        print("\n1.添加图书 2.删除图书 3.查询图书 4.借阅图书 5.归还图书 6.保存并退出")
        op = int(input("请输入选择："))
        if op == 1:
            isbn = input("ISBN:")
            n = input("书名:")
            a = input("作者:")
            s = int(input("库存:"))
            lib.add_book(Book(isbn,n,a,s))
        elif op == 2:
            isbn = input("输入要删除ISBN：")
            lib.del_book(isbn)
        elif op ==3:
            qn = input("输入查询书名：")
            r = lib.query_by_name(qn)
            for x in r:
                x.show_info()
        elif op ==4:
            isbn = input("借阅ISBN：")
            lib.borrow_book(isbn)
        elif op ==5:
            isbn = input("归还ISBN：")
            lib.return_book(isbn)
        elif op ==6:
            lib.save_json()
            print("已保存，退出")
            break