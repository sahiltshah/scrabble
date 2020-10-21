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

## Test Case:
### Input: 
we input the number of characters we have
```
10
```


each line hereon contains `<char> <frequency on the pallete> <corresponding character score>`
```
z 1 10 
g 1 6
o 1 4
t 1 5
y 1 9
i 1 3
k 1 8
a 1 1
e 1 2
l 1 7
```

### Output:
```
Node count is: 143643 leaf count: 58110 char count: 0
enter the number of unique characters: 
enter each character one after the one followed by the frequnecy and the score, eg, two 'a's of each score of 1 are :- [a 2 1]
the words in descending order of scores are: 
```
score | recommended word
```
40 glitzy // maximum score yield 
30 yokel
29 zealot
28 yolk
27 leaky
27 lazy
26 glaze
26 gaiety
26 gaily
26 talkie
25 italy
25 laity
25 legato
24 tyke
23 kilt
23 oily
23 yoke
23 gloat
22 okay
22 yogi
22 kilo
22 kelt
21 talk
21 alike
21 gilt
20 laze
20 yoga
20 zeal
20 like
19 zig
19 toil
19 gaze
19 yeti
19 ogle
19 yale
19 key
19 agile
18 yak
18 lake
18 ilk
18 goal
18 toy
18 gaol
18 kale
18 kite
18 leak
18 zeta
18 lye
17 glia
17 zag
17 elk
17 lay
17 tile
17 log
17 alto
16 gay
16 kit
16 take
16 toga
16 gale
16 keg
16 lot
16 tail
16 yet
16 goat
16 teak
15 gel
15 lit
15 leg
15 leat
15 tale
15 late
15 etal
15 got
15 teal
15 gait
15 tog
14 gal
14 agio
14 oil
14 lag
14 gate
14 let
14 aloe
13 oak
13 get
13 alt
13 iota
13 ole
12 ego
12 tag
12 yea
12 aye
12 ok
12 lie
11 ye
11 toe
11 ail
11 ago
10 ale
10 oat
10 go
10 lea
10 tie
9 age
9 to
8 eg
8 eat
8 it
8 eta
8 ate
8 tea
6 at
```
thus the answer is: `glitzy` with a score of 40
