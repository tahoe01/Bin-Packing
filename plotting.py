import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import scipy.interpolate as ip

def plot_timings_from_file(fname_list):
    for fname in fname_list:
        timings = pd.read_csv(fname, sep=',')

        n = timings['n'].values
        seconds = timings['seconds'].values

        x = n
        y = seconds
        plt.loglog(x=x, y=y, basex=2, basey=2)
        plt.plot(x, y, label=fname.rstrip(".csv"))


    plt.xlabel('# of elements')
    plt.ylabel('time in seconds')
    plt.title('Performance of sort')
    plt.legend()
    plt.show()
    # plt.savefig('uniform-shell.png')
    plt.close()

plot_timings_from_file(["bubble.csv", "insertion.csv", "spin.csv", "shell5.csv", "shell3.csv", "annealing2.csv", "annealing6.csv"])