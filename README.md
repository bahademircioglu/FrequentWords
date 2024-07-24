# Frequent Words
This project involves developing a C++ console application to analyze a text file consisting of tweets and determine the top 10 most frequent words. The text file is processed to exclude common stopwords, and the resulting words are counted and displayed in order of frequency.

Main Requirements
Input File: The project reads a text file containing tweet data in CSV format.
Tweet Data Format: The CSV file has the following fields:
Polarity of the tweet (0 = negative, 2 = neutral, 4 = positive)
ID of the tweet
Date of the tweet
Query (if no query, value is NO_QUERY)
User that tweeted
Text of the tweet (last field)
Stopwords
A list of stopwords can be found here. These words should not be counted in the frequency analysis.

For simplicity, a word is defined as any contiguous block of alphabetic characters (letters from “a” to “z”, both upper and lower case) which includes at most one single quotation mark between these letters.

After processing the file, the program must list the top 10 most frequent words in the tweets along with their counts. The total elapsed time for the operation should also be displayed.

Sample output:
<word1>
<word2>
<word3>
<word4>
<word5>
.
.
.
<word10>
<word count>
<word count>
<word count>
<word count>
<word count>
<word count>
Total Elapsed Time : X seconds

The project consists of the following components:

StopWatcher: For timing calculations, separating seconds and milliseconds.
TextReader: For opening and reading the input file.
Word: Manages individual word operations, checks for existing words, and increments their count.
WordGenerator: Prepares the read text string for further processing by converting to lower case and checking for empty strings.
WordHashList: A dynamic array implementation to handle word storage, including an expand function to double the array size when full.
WordsList: Performs most word operations like inserting, expanding the list, and printing.
WordTopList: Handles sorting of words using the merge sort algorithm.
These components are organized in multiple C++ files with appropriate headers. A general header includes necessary libraries such as iostream, ctime, etc.

The project supports Unicode to handle languages like Greek, Arabic, etc., using wmain and wchar.

Compilation and Execution
To compile the project, use the provided Visual Studio project directory. Ensure all necessary configurations are in place and build the solution. Run the executable from the command line to see the output.
