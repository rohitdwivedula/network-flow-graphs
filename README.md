# CS F364 - Design and Analysis of Algorithms
## Assignment 2

1. To implement the Ford-Fulkerson Algorithm.
2. Implement the subroutine to find the minimum st-cut of a network flow graph.
3. Use the Ford-Fulkerson algorithm for solving Bipartite Matching problem. 
4. Run your algorithm on different kinds of network flow graph for tasks 1 and 3. Smaller graphs to test your code and larger graphs to verify the robustness of implementations. Some of the bipartite graphs can be found in Stanford repository.
5. Record your experimental results along with the documentation of algorithm. Develop HTML pages to document the results produced by your code, issues in coding, general discussion on the algorithm, timing analysis, references, and any other remarks.
6. Use software Doxygen to produce the code documentation.

Team members: [Rohit Dwivedula](github.com/rohitdwivedula/), [Vamsi Nallappareddy](github.com/vam-sin/), [Varad Kshirsagar](https://github.com/Varad2305/).

# Installation and Running Instructions
1. Makefile (CMake) has been setup in the repo to make building the code easy. Build all the files using the command `make all` which will create object files `ford_fulkerson.o`, `min_st.o` and `bipartite_matching.o`. Alternatively, to build only one obj file use a command of the format `make ford_fulkerson` - for more details refer to the `Makefile` in this directory.
2. You will have to input the flow graph to analyse in a specific format - the first line should contain two integers  - the number of vertices (V) and edges (E). The next line should contain the index of the source and the sink (both < V). The next E lines should contain three integers each: the start node, the end node and the flow capacity. A couple of sample inputs are available in the directory `small_examples`. 
3. To run a small example use a command of this format: `cat small_examples/graph_1.txt | ./min_st.o`. The runtimes will be reported in all the runs, but for most small examples it'll show up as zero after rounding down. 
4. All the code has been formatted in the requisite way for Doxygen to work - on any system which has Doxygen installed, run `doxygen .doxygen-config` to generate HTML and Latex files. 

# Runtimes

## Ford Fulkerson
| Dataset | Edges | Vertices | Maximum Flow | Runtime |
|---|---|---|---|---|
| small_examples/graph_1.txt | 4 | 5 | 6 | ~0 seconds |
| small_examples/graph_2.txt | 6 | 6 | 7 | ~0 seconds |
| small_examples/graph_4.txt | 8 | 16 | 31 | ~0 seconds |
| flow_graph.txt | 4755  | 34247 | 251 | 19.056 seconds |

## Bipartite Matching

| Dataset | Edges | Vertices | Maximum edges in bpm | Runtime |
|---|---|---|---|---|
| out.brunson_revolution_revolution | 160 | 141 | 5 | ~0 seconds |
| out.moreno_crime_crime | 1476 | 1380 | 451 | 0.02 seconds |
| out.opsahl-collaboration | 58595 | 38741 | 12652 | 21.843 seconds |
| out.brunson_corporate-leadership_corporate-leadership | 99 | 44 | 20 | ~0 seconds |

# Resources Used and General Discussion

1. [This visualisation](https://www-m9.ma.tum.de/graph-algorithms/flow-ford-fulkerson/index_en.html) of the Ford Fulkerson algorithm was pretty helpful in understanding the algorithm, and was also useful in generating the small example graphs, which we made with the help of the GUI interface offered by this applet.
2. Once we understood the algorithm it was more or less pretty straightforward to implement. 