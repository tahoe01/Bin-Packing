import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import pandas as pd
import math
import random
from scipy import stats

def log_array(arr):
    return np.array([math.log(e, 10) for e in arr])

def get_regression_line_coefficients(x, y):
    return np.polyfit(log_array(x), log_array(y), 1)

def linear_regression():
    def plot_size_vs_times_log_log(fname):
        timings = pd.read_csv(fname, sep=',')
        n = timings['n'].values
        seconds = timings['seconds'].values

        x = n
        y = seconds
        plt.loglog(x, y, 's', basex=2, basey=2, label=fname)

    def plot_regression_lines(fname): 
        timings = pd.read_csv(fname, sep=',')
        n = timings['n'].values
        seconds = timings['seconds'].values

        m, b = get_regression_line_coefficients(n, seconds)       
        plt.plot(x, m*x + b, label=f'{fname.rstrip(".csv")}: y ~ {round(m, 2)}x + {round(b, 2)}')
    
    file_list = ["bubble.csv", "insertion.csv", "spin.csv", "shell5.csv", "shell3.csv", "annealing2.csv", "annealing6.csv"]
    
    # Plot graph
    plt.subplot(2, 1, 1)
    for fname in file_list:
        plot_size_vs_times_log_log(fname)
    plt.grid(which='both')
    plt.legend()
    
    # Linear regression
    x = np.array(range(6))
    plt.subplot(2, 1, 2)
    for fname in file_list:
        plot_regression_lines(fname)
    plt.legend()
    plt.grid(which='both')
    plt.xticks(x)
    plt.yticks(np.arange(12))

    plt.show()
    #plt.savefig('regression.png')
    plt.close()

linear_regression()
