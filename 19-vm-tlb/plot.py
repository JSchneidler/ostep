import re
import subprocess

import matplotlib.pyplot as plt

ITERATIONS = 10000


def run(pages, iterations):
    popen = subprocess.Popen(
        ["./tlb", str(pages), str(iterations)], stdout=subprocess.PIPE
    )
    popen.wait()
    output = popen.stdout.read()
    lines = output.splitlines()
    avg_line = lines[5]
    avg = re.search("\d+", avg_line.decode())

    return int(avg.group())


pages = [2**x for x in range(18)]
avgs = []
for i, num_pages in enumerate(pages):
    avg = run(num_pages, ITERATIONS)
    print(f"({i}) {num_pages}: {avg}")
    avgs.append(avg)

plt.plot(pages, avgs, marker="o")
plt.title(f"Avg access time by number of pages ({ITERATIONS} iters)")
plt.xlabel("Num pages")
plt.ylabel("Avg access time(ns)")
plt.xscale("log", base=2)

plt.show()
