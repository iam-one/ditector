import argparse
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

from config import DATA_PATH

sampleCur = [-1, 0, 3, 6, 9, 12, -7]
sampleTime = np.linspace(0, len(sampleCur) * 0.25, len(sampleCur))

current = []
maxCur = []
minCur = []

def sins(x, A, w):
    theta = w * x
    return A * np.sin(theta)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--data", type=str, help="")
    args = parser.parse_args()

    with open(DATA_PATH + str(args.data), 'r', encoding="utf-8") as file:
        for i, line in enumerate(file.readlines):
            current = line

            #TODO: show plt graph for 4 datas by timestamp
            #TODO: get max/min of Current

        sample_x = np.linspace(0, 4 * np.pi, 1000)

        popt, pcov = curve_fit(sins, sampleTime, sampleCur)

        print("Regression Sin Function: y = " + str(popt[0])[:8] + " sin(" + str(popt[1])[:8] + " * x)")
        print("Max/Min Current(Real): " + " / ")
        print("Max/Min Current(regression): " + str(popt[0])[:8] + " / " + str(-popt[0])[:9])
        print("sin 함수의 peak가 실제 측정 시 최댓값과 차이가 크다면, 표본이 부족하여 회귀식을 생성하는 데 오차가 있을 확률이 높습니다.")

        plt.plot(sample_x, sins(sample_x, *popt), color='red', linewidth=2)
        plt.show()