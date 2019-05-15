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
    def plot_size_vs_waste_log_log(fname):
        w = pd.read_csv(fname, sep=',')
        n = w['n'].values
        waste = w['waste'].values

        x = n
        y = waste
        plt.loglog(x, y, 's', basex=2, basey=2, label=fname)

    def plot_regression_lines(fname): 
        w = pd.read_csv(fname, sep=',')
        n = w['n'].values
        waste = w['waste'].values

        m, b = get_regression_line_coefficients(n, waste)       
        plt.plot(x, m*x + b, label=f'{fname.rstrip(".csv")}: y ~ {round(m, 2)}x + {round(b, 2)}')
    
    file_list = ["next_fit.csv", "first_fit.csv", "first_fit_decreasing.csv", "best_fit.csv", "best_fit_decreasing.csv"]
    
    # Plot graph
    plt.subplot(2, 1, 1)
    for fname in file_list:
        plot_size_vs_waste_log_log(fname)
    plt.grid(which='both')
    plt.title('Regression Analysis of Bin Packing Algorithms')
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

    plt.savefig('waste-regression.png', dpi = 100)
    plt.show()
    plt.close()

linear_regression()
