all: ford_fulkerson min_st bipartite_matching

ford_fulkerson:
	g++ -o ford_fulkerson.o ford_fulkerson.cpp ford_fulkerson.h utils.h

min_st:
	g++ -o min_st.o min_st.cpp min_st.h utils.h

bipartite_matching:
	g++ -o bipartite_matching.o bipartite_matching.cpp