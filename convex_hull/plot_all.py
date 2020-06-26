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

df = [None] * 2

df[0] = pd.read_csv('results/chan_n.csv')
df[1] = pd.read_csv('results/graham_n.csv')

n = [None] * 2
rt = [None] * 2

for i in range(2):
    n[i] = df[i]['n'].values
    rt[i] = df[i]['runtime'].values

labels = ["Chan's", "Graham Scan"]

for i in [0, 1]:
    plt.plot(n[i], rt[i], label=labels[i])

plt.xlabel("n")
plt.ylabel("time (us)")
# plt.xscale("log")
plt.legend()
# plt.show()
plt.savefig(f'results/plots/all.pdf')
