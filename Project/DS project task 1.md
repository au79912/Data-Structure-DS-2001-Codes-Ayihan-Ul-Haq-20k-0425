# TASK 1 - Brute Force

- The first major execution of this code is to run the **SOLVER Threads** so that they can store the answers to the puzzles that have been programmed in the code and store those answers for later comparison with the **MINER Threads.**








- **Puzzle 1** is a random number generated from 45-80 for the Solver 1 thread to iteratively find the fibonacci number present at that place.





- **Puzzle 2**  is also a random number generated from 1-100000 and the Solver 2 thread finds that number through iterating through the numbers until the random number matches its current iteration.











- **Puzzle 3** is a string that is generated and a substring is defined , the Solver thread 3 filles a empty string and fills it letter by letter until the substring is found












- After all the Solver threads have been executed and the answers have been stored the **Miner Threads** are called and are all joined.











- **MINER 1**
  - The miner one brute force the puzzle that is corresponds with the random number generated “n”, If n is 0 then it will move to brute forcing the fibonacci series iterative 













- If n = 1 then it will move to brute forcing the random number for i = 0















