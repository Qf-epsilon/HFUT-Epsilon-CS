import cv2
import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

img = cv2.imread("apple.png")
if img is None:
    print("未找到apple.png")
else:
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    hist = cv2.calcHist([gray],[0],None,[256],[0,256])
    max_hist_idx = np.argmax(hist)
    ys,xs = np.where(gray == max_hist_idx)
    for px,py in zip(xs,ys):
        cv2.circle(img,(px,py),2,(0,255,0),-1)

    plt.figure(figsize=(12,4))
    plt.subplot(1,3,1)
    plt.imshow(cv2.cvtColor(img,cv2.COLOR_BGR2RGB))
    plt.title("原始图像标记")
    plt.axis("off")
    plt.subplot(1,3,2)
    plt.imshow(gray,cmap="gray")
    plt.title("灰度图")
    plt.axis("off")
    plt.subplot(1,3,3)
    plt.plot(hist)
    plt.title("灰度直方图")
    plt.xlabel("灰度")
    plt.ylabel("像素数")
    plt.tight_layout()
    plt.show()