import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import scipy.interpolate as ip

def plot_waste_from_file(fname_list):
    for fname in fname_list:
        w = pd.read_csv(fname, sep=',')

        n = w['n'].values
        waste = w['waste'].values

        x = n
        y = waste
        plt.loglog(x=x, y=y, basex=2, basey=2)
        plt.plot(x, y, label=fname.rstrip(".csv"))


    plt.xlabel('N: number of items')
    plt.ylabel('Waste(N)')
    plt.title('Quality of Bin Packing Algorithms')
    plt.legend()
    
    plt.savefig('waste.png', dpi = 100)
    plt.show()
    plt.close()

plot_waste_from_file(["next_fit.csv", "first_fit.csv", "first_fit_decreasing.csv", "best_fit.csv", "best_fit_decreasing.csv"])