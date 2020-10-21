# scrabble

## Usage Instructions
1. Clone the folder or Fork it
2. `chmod +x scrabble_find.sh` to change usage permissions for the [file](https://github.com/sahiltshah/scrabble/blob/master/scrabble_find.sh)
3. Suitably modify the `scrabble_find_input.txt` [file](https://github.com/sahiltshah/scrabble/blob/master/scrabble_find_input.txt)
4. Simply run the [shell script](https://github.com/sahiltshah/scrabble/blob/master/scrabble_find.sh) by typing `./scrabble_find.sh`
5. Check the [scrabble_find_output.txt](https://github.com/sahiltshah/scrabble/blob/master/scrabble_find_output.txt) file for the desired output

## Working
1. We rely on the Words list found in [words.txt](https://github.com/sahiltshah/scrabble/blob/master/words.txt) file and use `fstream` to load all the words
2. All the words are stored in the form of a Trie
3. From the [input file](https://github.com/sahiltshah/scrabble/blob/master/scrabble_find_input.txt) we maintain a map: `map<char,int>` and array:`int f[26]` to store the corresponding scores and frequencies of each letter on the pallete
4. We use a slightly modified trie-search function to look for all possible word-paths that are 'affordable' within the user-inputed frequencies
5. We store all the word matches into a `vector<string>` named `recommendation`
6. We sort `recommendation` by the decreasing order of the scores they yield using a user-defined boolean comparator function: `bool compareRecommendation()` and `int score_word()`
