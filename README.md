# Data Structures and Algorithms
From-scratch attempts at implementing some common data structures and algorithms.
 
Currently, this repo contains (both bug-free and buggy) versions of code I've written to try to get a better understanding of the under-the-hood inner workings of various data structures. 
 
As of this writing (23 July 2022), most of the code is in `Python3`, though some `Java` and `C++` updates have started to creep in as well. Future iterations will include more `Java` and `C++` code, and perhaps some other languages as well. **Update:** Due to some changes in circumstance, `C++` may become the main focal point of my contributions; we shall see.

As of 3 July 2022, a study guide has also made its way into the repo. This study guide is `LaTeX`'ed and is intended to help guide my studies + document the journey so far. **Update:** Later, I removed the `TeX` source code from the repo so that the code percentages would better reflect my _real_ contributions rather than showing a repo with 80% `TeX` code!

## TODO:
 * Refactor `*Hash` challenge problems to abandon generics in favor of `int` types (because otherwise, binning for floats, etc., is bad news!).
 * Incorporate more headers for new `LinkedList.cpp` file.
 * Work on porting the old `C++` singly linked list + doubly linked list algorithms to the new `LinkedList.cpp` implementation.
 * Make sure `C++` files adhere to best practices re: [Rule of Three/Five/Zero](https://en.cppreference.com/w/cpp/language/rule_of_three) and [RAII](https://en.cppreference.com/w/cpp/language/raii). 
 * Continue adding to `SparseMatrixStruct.cpp` and `SparseMatrix.cpp` (include subtraction; possibly multiplication?).
 * Get all the `Python` code translated in to `C++` (!!!) and `Java` (as time permits).
 * Translate `Array` ADT from `C++` to `Python` and `Java`.
 * Get study guide source re-added so I can work on it elsewhere.
 * Keep working on the study guide.

<details>
<summary><h2>Changelog</h2></summary>
<h3>8 Jun 2023</h3>
<ol>
    <li>In <code>LinkedList.cpp</code>: Added new example + <code>SortedQ()</code>.</li>
    <li>Later, added <code>DeleteDuplicates()</code> in <code>LinkedList.cpp</code>.</li>
    <li>Eventually, swapped order of parameters for <code>Insert(...)</code> to better match what happens in the <code>Array</code> ADT.</li>
    <li>Added <code>Reverse()</code> functionality to <code>LinkedList.cpp</code>.</li>
</ol>
<h3>7 Jun 2023</h3>
<ol>
    <li>Added <code>Display()</code> to <code>LinkedList.cpp</code>.</li>
    <li>Later, added <code>Length()</code>, <code>Sum()</code>, <code>Min()</code>, and <code>Max()</code> to <code>LinkedList.cpp</code>.</li>
    <li>Added <code>Insert(...)</code> to <code>LinkedList.cpp</code>.</li>
    <li>Later, added <code>Delete(...)</code> to <code>LinkedList.cpp</code>, and later, made a small edit to <code>Delete(...)</code>.</li>
    <li>At home, moved <code>CPP/SinglyLinkedList/</code> and <code>CPP/DoublyLinkedList</code> to <code>/Obsolete/CPP/</code> per inclusion of new <code>/LinkedList/</code> files.</li>
</ol>
<h3>6 Jun 2023</h3>
<ol>
    <li>Changed <code>LinkedList.cpp</code> to have <code>head</code> as a pointer + percolated the associated method changes throughout.</li>
    <li>Changed the name of old-<code>LinkedList.cpp</code> file to <code>LinkedListLegacy.cpp</code>.
</ol>
<h3>31 May 2023</h3>
<ol>
    <li>Initial commit of <code>Node.h</code> and <code>LinkedList.cpp</code>; the particulars of this were written last week but uncommitted.</li>
</ol>
<h3>26 May 2023</h3>
<ol>
    <li>Updated the study guide.</li>
</ol>
<h3>24 May 2023</h3>
<ol>
    <li>Initial commit of <code>SparseMatrix.h</code> and <code>SparseMatrixNew</code>, featuring hard-coded <code>int</code>-type data <code>Element.x</code>. I'm still trying to figure out the intricacies of the templating for non-integer types.</li>
    <li>Later, deleted those two files to try to figure out stuff.</li>
    <li>After much work + help on Stack Overflow: Got <code>SparseMatrix.cpp</code> to work with generics / templating. I'm an idiot for not considering forward-declaration as a solution sooner; forward-declaration literally solved one of my <code>Array.h</code> problems the other day!</li>
    <li>Split <code>SparseMatrix.cpp</code> into <code>Element.h</code> and <code>SparseMatrix.h</code>.</li>
</ol>
<h3>23 May 2023</h3>
<ol>
    <li>Initial commit of <code>SparseMatrixStruct.cpp</code>.</li>
    <li>Later, added <code>Add()</code> functionality to <code>SparseMatrixStruct.cpp</code>.</li>
    <li>Uploaded initial commit of <code>SparseMatrix.cpp</code>, which uses <code>class</code>es instead of <code>struct</code>s.</li>
    <li>Later: Swapped <code>Read()</code> and <code>Display()</code> for overloaded <code>cin</code> and <code>cout</code>.</li>
    <li>Even later: Implemented old <code>Add()</code> as custom <code>SparseMatrix::operator+</code> operator.</li>
</ol>
<h3>22 May 2023</h3>
<ol>
    <li>In <code>LowerTriangularMatrix.cpp</code>: Revamped loops to start at <code>i=1</code> and <code>j=1</code>.</li>
    <li>Later, initial commit of <code>UpperTriangularMatrix.h</code> and <code>UpperTriangularMatrix.cpp</code> using row-major mapping.</li>
    <li>Used <code>LowerTriangularMatrix*</code> to build initial commit of <code>SymmetricMatrix*</code>---and later, <code>TridiagonalMatrix*</code>---files.</li>
    <li>Fixed bug in <code>ShortPrint()</code> for <code>SymmetricMatrix.cpp</code>.</li>
    <li>Later, fixed indexing bug in <code>TridiagonalMatrix.cpp</code> and fixed typo in <code>README</code>.</li>
    <li>Even later: Initial commit of <code>ToeplitzMatrix.h</code> and <code>ToeplitzMatrix.cpp</code>.</li>
</ol>
<h3>18 May 2023</h3>
<ol>
    <li>Added destructor to Array ADT in <code>C++</code>.</li>
    <li>Created <code>CPP/Matrices</code> directory + added initial commit of <code>DiagonalMatrix</code> files (<code>.cpp</code> and <code>.h</code>).</li>
    <li>Later, created <code>C++</code> files <code>LowerTriangularMatrix.h</code> and <code>LowerTriangularMatrix.cpp</code> using row-major mapping.</li>
    <li>Improved commenting in <code>Array.h</code>, <code>DiagonalMatrix.cpp</code>, and <code>LowerTriangularMatrix.cpp</code>.
    <li>Added a driver to <code>LowerTriangularMatrix.cpp</code> to allow for entering a whole matrix all at once.</li>
</ol>
<h3>16 May 2023</h3>
<ol>
    <li>In <code>C++</code> Array ADT: Added Setters, in part to allow the <code>public</code> <code>T* A</code> to become private.</li>
    <li>Later, declared <code>Union2</code> as a <code>friend</code> function to allow access to private member variables.</li>
    <li>Added better commenting to show the breakdown of functions throughout code.</li>
    <li>Later, moved legacy functions to <code>ArrayLegacy.cpp</code> and renamed <code>Union2</code> and <code>Union3</code> both as <code>Union</code>.</li>
    <li>Also: Implemented <code>friend</code> versions of <code>Intersection</code> and <code>Complement</code>.</li>
    <li>Later still: Changed a number of dereferencing operations to <code>-></code>s.</li>
    <li>Also, added <code>Intersection</code>, <code>Complement</code> member functions.</li>
</ol> 
<h3>15 May 2023</h3>
<ol>
    <li>In <code>C++</code> Array ADT: Added functionality for <code>Intersection</code> and <code>Complement</code>.</li>
    <li>Later, simplified <code>Intersection</code> algorithm and changed the existing algorithm to <code>LegacyIntersection</code> for posterity.</li>
    <li>Eventually figured out a non-<code>Void</code> version of <code>Union</code> in <code>C++</code> Array ADT. This will be fleshed out more soon.</li>
    <li>Mimicked non-member <code>Union2</code> code into member function <code>Union3</code>.</li>
</ol> 
<h3>12 May 2023</h3>
<ol>
    <li>Made some small code tweaks to the Array ADT in <code>C++</code>, and later, added support for <code>Contains</code> and <code>(Unsorted) Union</code>.</li>
</ol> 
<h3>11 May 2023</h3>
<ol>
    <li>To Array ADT in <code>C++</code>: Added <code>Get</code>, <code>Set</code>, <code>Sum</code>, <code>Avg</code>, <code>Max</code>, and <code>Min</code>.</li>
    <li>Later, rewrote some code in a clearer manner + deleted some commented-out code in <code>C++</code> Array ADT.</li>
    <li>In Array ADT <code>C++</code> files: Added <code>Reverse</code>, <code>LeftShift</code>, <code>LeftRotate</code>, <code>RightShift</code>, <code>RightRotate</code>.</li>
    <li>Added functionality in Array ADT for <code>SortedInsert</code>, <code>IsSorted</code>, and <code>PosNegSwap</code>.</li>
    <li>Later, improved incapsulation in Array ADT by making member vars private + adding getters.</li>
</ol> 
<h3>10 May 2023</h3>
<ol>    
    <li>Committed initial version of Array ADT in <code>C++</code> (both <code>.cpp</code> and <code>.h</code> files).</li>
    <li>Later, fixed up some pointer-related things in Array ADT.</li>
</ol> 
<h3>19 Aug 2022</h3>
<ol>
    <li>Made some small edits to linked list in <code>C++</code></li>
    <li>Completed doubly linked list in <code>C++</code> with generics.</li>
</ol>
<h3>14 Aug 2022</h3>
<ol>
    <li>Completed singly linked list in <code>C++</code> with generics.</li>
    <li>Learned more about pointers, but still need additional refresher.</li>
</ol>
<h3>12 Aug 2022</h3>
<ol>
    <li>Started working on singly linked lists in <code>C++</code>.</li>
    <li>In so doing, realized I have <b>a lot</b> to (re-)learn (for the 17th time) about pointers.</li>
</ol>
<h3>10 Aug 2022</h3>
<ol>
    <li>Got a 0<sup>th</sup> draft of hash sets working in <code>C++</code>. To get this working, I had to abandon my aspirations for generic types and just stick with integers. Generic types will come soon! ::crosses fingers::</li>
    <li>Later, added <b>working</b>(!!!) generics to <code>C++</code> hash sets.</li>
    <li>Also, removed references to <code>this->*</code>, as that doesn't appear to be very <code>C++</code>-like? :shrug:</li>
</ol>
<h3>23 Jul 2022</h3>
<ol>
    <li>Decided to try my hand at hash sets in <code>C++</code> after having not written <code>C++</code> code in 15 years. It did <b>not</b> go well!</li>
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
