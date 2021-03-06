# Data Structures and Algorithms
From-scratch attempts at implementing some common data structures and algorithms.
 
Currently, this repo contains (both bug-free and buggy) versions of code I've written to try to get a better understanding of the under-the-hood inner workings of various data structures. 
 
As of this writing (23 July 2022), most of the code is in `Python3`, though some `Java` and `C++` updates have started to creep in as well. Future iterations will include more `Java` and `C++` code, and perhaps some other languages as well.

As of 3 July 2022, a study guide has also made its way into the repo. This study guide is `LaTeX`'ed and is intended to help guide my studies + document the journey so far.

<details>
<summary><h2>Changelog</h2></summary>
<h3>23 Jul 2022</h3>
<ol>
    <li>Decided to try my hand at Hash Maps in <code>C++</code> after having not written <code>C++</code> code in 15 years. It did <b>not</b> go well!</li>
    <li>Made some small tweaks to the <code>Java</code> Hash Map file.</li>
    <li>Edited the README and the .gitignore files.</li>
    <li>Later, removed some of the <code>Python</code> test code so the GitHub calculator thing gets the language percentages more accurate.</li>
</ol>
<h3>16 Jul 2022</h3>
<ol>
    <li>Filled in the <code>Stacks and Queues</code> section of the study guide.</li>
    <li>Also, added in the <code>Stack</code> and <code>Queue</code> rows of the first-page complexity table.
</ol>
<h3>12 Jul 2022</h3>
<ol>
    <li>Made a few small edits to the study guide.</li>
    <li>Also, added a section for <code>Stacks and Queues</code> + filled in the subsections a bit before bedtime.</li>
</ol>
<h3>9 Jul 2022</h3>
<ol>
    <li>Made some complexity-related edits to the study guide.</li>
</ol>
<h3>8 Jul 2022</h3>
<ol>
    <li>Renamed the repo to include common algorithms. Will ultimately restructure the directories as well.</li>
    <li>Later, restructured all subdirectories.</li>
    <li><p>Much later, wrote + uploaded initial versions of <code>SelectionSort</code> for both <code>Python3</code> and <code>Java</code>.</p>
    <p>Both versions include the algorithm, as well as a <code>SelectionSortAnalysis</code> method/function which shows how the number of steps grows as the size of the input array doubles.</p>
    <p>What I <i>reallllllly</i> want to show is how time increases, not code count. I'll do some digging into that soon and try to implement ASAP.</p></li>
    <li>Much later still, updated the study guide pretty heavily, including uses of newly-included images and a new <text>.gitignore</text> file.</li>
</ol>
<h3>7 Jul 2022</h3>
<ol>
    <li>Big changes to the study guide, including:
    <ul>
        <li><i>Data Structures</i> and <i>Search Algorithms</i> main sections.</li>
        <li>A full-populated and linked search algorithm complexity table.
        <li>A fully-written section on <b>Selection Sort</b> (plus a lot of dummy text for other sort algorithms).</li>
    </ul>
</ol>
<h3>6 Jul 2022</h3>
<ol>
    <li>First upload of a Java version (<code>HashSet</code>) plus a general restructuring of directory structure + a revamped <code>.gitignore</code> file.</li>
</ol>
<h3>4 Jul 2022</h3>
<ol>
    <li>I added some details to the study guide, and implemented BFS to the <code>BST.py</code> file. Next up, I plan to implement some deletion methods, and possibly to adapt some BST-implemented methods to code a less-specific brand of tree.</li>
</ol>
<h3>3 Jul 2022</h3>
<ol>
    <li>I'm keeping a study guide to go along with my explorations into these data structures/algorithms. I decided it was a good idea to upload the related .tex, .sty, and .pdf files.</li>
    <li>Later, added BST information to both <code>Okay</code> directory (in Python3) and study guide.
</ol>
<h3>27 Jun 2022</h3>
<ol>
    <li>1. Used some snippets from <a href = "https://stackoverflow.com/questions/68974018/insert-at-index-in-linked-list">this answer</a> to prototype a redo of SinglyLinkedList. This code + the code in the accepted comment contained >= 2 very serious bugs and needed quite a bit of plussing up, so I did that plus thoroughly documented everything before **finally** reaching the level of "accepted LeetCode answer."</li>
</ol>
<h3>26 Jun 2022</h3>
<ol>
<li>Initial upload.</li>
<li>Later, updated the README.md file to its current state.</li>
<li>Approximately 22 hours later, attempted to use <a href = "https://www.geeksforgeeks.org/data-structures/linked-list/">the GeeksForGeeks solution</a> as an inspiration for a new implementation of SinglyLinkedList, only to find that this one times out on <a href = "https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1290/">LeetCode</a>. I think my best plan of action moving forward will be to try a whole new implementation; I have some ideas!</li>
</ol>
</details>
