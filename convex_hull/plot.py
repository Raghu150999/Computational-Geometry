import numpy as np
import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use("pgf")
matplotlib.rcParams.update({
    "pgf.texsystem": "pdflatex",
    'font.family': 'serif',
    'text.usetex': True,
    'pgf.rcfonts': False,
})
plt.style.use("ggplot")

n = 1000000

df = [None] * 3

df[0] = pd.read_csv('results/chan_results.csv')
df[1] = pd.read_csv('results/graham_results.csv')
df[2] = pd.read_csv('results/jarvis_results.csv')

h = [None] * 3
rt = [None] * 3

for i in range(3):
    df[i] = df[i][df[i]['n'] == n]
    h[i] = df[i]['h'].values
    rt[i] = df[i]['runtime'].values

labels = ["Chan's", "Graham Scan", "Jarvis March"]

for i in [0, 1]:
    plt.plot(h[i], rt[i], label=labels[i])

plt.xlabel("h")
plt.ylabel("time (us)")
plt.xscale("log")
plt.title(f"Running time comparison for n = {n}")
plt.legend()
# plt.show()
plt.savefig(f'results/plots/n{n}.pdf')
