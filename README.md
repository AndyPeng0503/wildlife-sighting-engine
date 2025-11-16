# Wildlife Sighting Search Engine

This project implements a simple tool for searching wildlife sighting records based on their computed signatures.  
Each sighting is assigned a signature using its speed and brightness, and the program checks how many target signatures appear in the dataset.
The project provides both a linear search and a binary search version to compare performance and behavior.

## Features
- Computes a signature for each sighting based on speed and brightness.
- Supports both linear search and binary search methods.
- Includes a small dataset generator (`create_dataset.py`) for testing.
- Provides a reference program for verifying correctness.

## How to Build
```bash
g++ -std=c++11 sighting_search.cc -o sighting_search
