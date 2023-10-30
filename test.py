import numpy as np
import matplotlib.pyplot as plt

timeStamp = np.arange(0, 5*np.pi, 0.1)
resVol = np.sin(timeStamp) + 50

resVolMax = resVol[0]
resVolMin = resVol[0]

x = timeStamp
y = resVol

for vol in resVol:
    if vol > resVolMax:
        resVolMax = vol
    elif vol < resVolMin:
        resVolMin = vol

print("peak: " + str(resVolMax) + ", " + str(resVolMin))

plt.plot(x, y, '.')
plt.show()