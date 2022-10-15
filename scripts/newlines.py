import os
from glob import glob

if __name__ == "__main__":
    for filepath in glob("**/*.*pp", recursive=True):
        with open(filepath, "r") as stream:
            assert stream.read().endswith("\n")
