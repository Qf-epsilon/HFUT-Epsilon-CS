import turtle

def draw_polygon(n,length):
    for _ in range(n):
        turtle.forward(length)
        turtle.left(360/n)

colors = ["red","blue","green","orange","purple"]
side_list = [3,4,5,6,8]
turtle.pensize(3)
for i,sides in enumerate(side_list):
    turtle.color(colors[i])
    draw_polygon(sides,100)
    turtle.penup()
    turtle.forward(130)
    turtle.pendown()

turtle.done()