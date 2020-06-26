import matplotlib.pyplot as plt
import argparse
import csv
import subprocess as sp
from io import StringIO
from pathlib import Path


def next_run_id(results_file: Path):
    lines = results_file.read_text().splitlines()
    try:
        row = next(csv.reader([lines[-1]]))
        return int(row[0]) + 1
    except (ValueError, IndexError):
        return 1


def gen_dataset(n, h):
    sp.call([f'./test_long {n} 1'], shell=True, stdout=sp.PIPE)
    return


def run_convex_hull(exec_path):
    data = open("./tests/data.txt")
    return sp.check_output([exec_path], input=data.read(), text=True)


def run(
    exec_path,
    results_dir: Path,
    run_id: str
):
    runtime = run_convex_hull(exec_path)
    return runtime


def gen_imp_nums(start=10, stop=1e7, scale=10):
    while start * scale <= stop:
        yield start
        yield start * 2
        yield start * 5
        start *= scale


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("exec_path", type=str,
                        help="Path to clustering executable")
    parser.add_argument(
        "--results_dir",
        type=Path,
        default=(Path.cwd() / "results"),
        help="Path where results will be stored",
    )
    args = parser.parse_args()
    results_file = args.results_dir / "results.csv"
    if not results_file.exists():
        # write headers if file is new
        with open(results_file, "w") as f:
            w = csv.writer(f)
            w.writerow(
                (
                    "id",
                    "n",
                    "h",
                    "runtime",
                )
            )
        run_id = 1
    else:
        run_id = next_run_id(results_file)

    for n in gen_imp_nums(start=100):
        for h in range(1):
            gen_dataset(n, h)
            print(f"Running test: {n} {h}")
            runtime = run(
                args.exec_path,
                args.results_dir,
                f"{run_id:08}"
            )
            with open(results_file, "a") as f:
                w = csv.writer(f)
                w.writerow(
                    (
                        f"{run_id:08}",
                        n,
                        h,
                        int(runtime),
                    )
                )
            run_id += 1


if __name__ == "__main__":
    main()
