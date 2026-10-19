import numpy as np
import cv2
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

if __name__ == '__main__':
    h, w = 300, 400
    b = np.tile(np.linspace(0, 255, w, dtype=np.uint8), (h, 1))
    g = np.tile(np.linspace(0, 255, h, dtype=np.uint8).reshape(-1,1), (1, w))
    r = 255 - b
    img_bgr = np.dstack([b, g, r])

    gray = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2GRAY)
    hist = cv2.calcHist([gray], [0], None, [256], [0, 256])

    plt.figure(figsize=(12,4))
    plt.subplot(1,3,1)
    plt.imshow(cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB))
    plt.title('彩色图像')
    plt.axis('off')

    plt.subplot(1,3,2)
    plt.imshow(gray, cmap='gray')
    plt.title('灰度图像')
    plt.axis('off')

    plt.subplot(1,3,3)
    plt.plot(hist, color='black')
    plt.title('灰度直方图')
    plt.xlabel('灰度级（0~255）')
    plt.ylabel('像素个数')
    plt.xlim([0,256])

    plt.tight_layout()
    plt.show()

    print("直方图物理意义：")
    print("横轴代表灰度0‑255，0黑255白；纵轴代表对应灰度的像素数量。")
    print("直方图反映图像像素明暗分布，可以看出图像的亮度和对比度情况。")