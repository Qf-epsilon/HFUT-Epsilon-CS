import turtle

colors = ["red", "blue", "green", "yellow", "purple"]
t = turtle.Turtle()
t.pensize(15)

for c in colors:
    t.pencolor(c)
    t.circle(40, 80)
    t.circle(-40, 80)

turtle.done()