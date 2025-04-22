# FrequentWords

C++ Console App for Top‑10 Word Frequency

## Overview

Analyzes a CSV of tweets, excludes stopwords, and prints the top 10 most frequent words along with execution time.

## Features

- Reads tweet CSV: polarity, ID, date, query, user, text  
- Excludes configurable stopwords list  
- Uses merge sort for ranking  
- Unicode support for non‑Latin scripts

## Prerequisites

- Visual Studio or g++ compiler  
- C++11 support

## Installation

```bash
git clone https://github.com/bahademircioglu/FrequentWords.git
cd FrequentWords
```

## Build & Run

- **Visual Studio**: open solution and build  
- **GCC**:

  ```bash
  g++ -std=c++11 *.cpp -o freqwords
  ./freqwords tweets.csv stopwords.txt
  ```

Output includes top 10 words and elapsed time.

## Project Structure

```
FrequentWords/
├── data_st_project_final/
├── stopwords.txt
├── *.cpp, *.h
├── LICENSE (GPL-3.0)
└── README.md
```

## Contributing

Contributions welcome via issues or PRs.

## License

GPL‑3.0 License.
