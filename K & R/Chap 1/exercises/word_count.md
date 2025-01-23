#### Word Count

> How would you test the word count program? what kinds of input are most likely to uncover bugs if there are any?


#### Solution
Verify the core logic for counting lines, words, and characters:

    Empty input: "" → Expect 0 0 0.

    Single character: "a" → Expect 0 1 1 (0 lines, 1 word, 1 character).

    Single word: "hello" → Expect 0 1 5.

    Single line with spaces: "hello world" → Expect 0 2 11 (11 characters include the space).

    Multiple lines: "line1\nline2" → Expect 2 2 12 (two lines, two words, 12 characters including \n).