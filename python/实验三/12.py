import matplotlib.pyplot as plt

courses = ["Python", "Math", "English", "Physics", "Chemistry"]
scores = [88, 92, 79, 85, 90]
colors = ["red", "orange", "yellow", "green", "blue"]

bars = plt.bar(courses, scores, color=colors)

for bar in bars:
  height = bar.get_height()
  plt.text(
      bar.get_x() + bar.get_width() / 2.0,
      height + 1,
      str(height),
      ha="center",
      va="bottom",
  )

plt.ylim(0, 105)
plt.xlabel("课程")
plt.ylabel("成绩")
plt.title("平均五门课柱状图")
plt.show()