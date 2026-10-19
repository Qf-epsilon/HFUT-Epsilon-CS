class Rectangle:

  def __init__(self, length, width):
    self.length = length
    self.width = width

  def s(self):
    return self.length * self.width

  def c(self):
    return 2 * (self.length + self.width)

rect = Rectangle(5, 3)
print(f"矩形面积: {rect.s()}")
print(f"矩形周长: {rect.c()}")