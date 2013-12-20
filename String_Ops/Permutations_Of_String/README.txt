Objective:
==========
This program calculates the permutations of the given string. The main idea behind the algorithm is to fix one character and then find the permutations of the rest of the string. i.e it uses the concept n! = n*(n-1)!. 

Example:
========
Let us consider the string abcd.
1. First we fix a, and find the permutations of "bcd". This is done recursively. So we then fix b, and find the permutations of "cd". Then we fix 'c' and find the permuations of "d". Now when we reach the length of the string, we go ahead and print the string.
2. Once we find the permutations of the string starting with a, we then find the permutations of the string starting with 'b' using the same logic above till we exhaust all the characters.

Explanation of the Program:
========================== 

swap - Swaps two characters.

perm - Main function which does the permution. The parameter 'k' denotes the index of the character we are fixing. 'n' denotes the length of the string. When k = 0, we mean, we fix the 1st character in the string and find the permutation for rest of the characters. In the "abcd" example, we fix 'a' and find the permutations of "bcd". Recursively, when we fix k = 1, it means we are fixing the character 'b' and finding the permutations of "cd". The backtracking is necessary because we have to restore the string back to its original condition as we find the remaining permutations assuming the string is stored in order.
