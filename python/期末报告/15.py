import jieba
from wordcloud import WordCloud
from collections import Counter

with open("水浒传.txt","r",encoding="utf-8") as f:
    text = f.read()

words = jieba.lcut(text)
cnt = Counter(words)
top20 = cnt.most_common(20)
print(top20)

wc = WordCloud(font_path="simhei.ttf",width=800,height=600,background_color="white")
wc.generate(" ".join(words))
wc.to_file("shuihu_wc.png")