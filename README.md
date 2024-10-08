# Impledge-Task🌐
**Steps to execute the source code:**

->Firstly, we will make sure we have a C++ compiler like g++ installed on our computer.

->Next, create a folder in the directory, and save the code in a file named **WordCompositionProblem.cpp** inside that folder.

->In the same folder, insert the input text files named Input_01.txt and Input_02.txt.

->Now, we need to compile the code,simply click the run button then the program will read the words from the input file that is first given,then it'll figure out the longest and 
  second-longest compound words, and display them,along with the time it took to process everything.
  
  -------------------------------------------------------


**Overview of my program:**

->In this program we have to find the longest and second-longest compound words. A compound word is defined as a word that can be constructed by concatenating two or more smaller words from the same list.

-> The program uses dynamic programming with memoization to efficiently check if a word is a compound word. The memoization technique stores results of subproblems to avoid redundant computations, enhancing the performance.

->To do this, the program first will read all the words from the file and stores them in a vector. It then uses an unordered_set to efficiently check if parts of a word exist in the list. The core logic is handled by a recursive function that attempts to break down each word into valid subwords, identifying compound words along the way.

->I have designed this using fast lookups. It also measures the time taken to process the file, providing a clear indication of its efficiency. This simple approach allows the program to quickly identify and display the longest compound words in the list.

-------------------------------------------------------


**Approach Used:**

I used the concept of **Dynamic Programming** and **unordered_set** to store the list of words that allows for O(1) average-time complexity for lookups. It is crucial because it enables fast checking to see if a substring or a word exists in the list, which is fundamental for identifying compound words.


**Conclusion:**

The best aspect of this program is its quick execution. It efficiently processes the input and returns results rapidly, making it well-suited for handling large lists of words.

## Output Screenshots:
1. **Output for text file-01:**
   
   ![Output-1](https://github.com/kashish281/Impledge-Task/blob/main/Output-1.png)

2. **Output for text file-02:**
   
   ![Output-2](https://github.com/kashish281/Impledge-Task/blob/main/Output-2.png)

  -------------------------------------------------------
 
## Special Thanks

I would like to extend my gratitude to **Impledge Technologies** for giving me the opportunity to work on this project as a part of their Qualifier Round assignment. I appreciate the time and effort they took to evaluate my skills and provide me with a chance to showcase my abilities. Thank you for the experience.






