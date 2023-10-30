import argparse
import math
import matplotlib as plt
import numpy as np
import pandas as pd
from scipy.optimize import curve_fit

from config import DATA_PATH

resVol, indVol, resCur, indCur, timeStamp = [], [], [], [], []

timeStamp = [lambda x: x, range(0, 15)]
resCur = [0, 1, 2, 3, 4, 3, 2, 1, 0, -1, -2, -3, -4, -3, -2]

def curSin(x, a, b, c):
    return a * math.sin(b * x) + c

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--data", type=str, help="")
    args = parser.parse_args()

    with open(DATA_PATH + str(args.data), 'r', encoding="utf-8") as file:
        # for i, line in enumerate(file.readlines):
        #     resVol[i] = line.split(",")[0]
        #     indVol[i] = line.split(",")[1]
        #     resCur[i] = line.split(",")[2]
        #     indCur[i] = line.split(",")[3]
        #     timeStamp[i] = line.split(",")[-1]

            #TODO: show plt graph for 4 datas by timestamp
            #TODO: get max/min of Current
            #TODO: get sin-shape function for intensity of current

        popt, pcov = curve_fit(curSin, timeStamp, resCur)
        plt.plot(timeStamp, curSin(timeStamp, popt))

        plt.scatter(timeStamp, resVol, marker='.')