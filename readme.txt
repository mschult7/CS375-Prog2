The program compiles by running >make all
It can then be executed by >./BestFirstSearch input.txt output.txt

This program uses multiple vectors p,w,and include. p stores the prices of every item
and w stores the weight, while include stores true or false values which at the end are used
to reconstruct the items which when chosen produce the maximum profit.

I also use a priority_queue called PQ which i set up with a custom priority in the included class nodecomp
which determines priority by the nodes bound.
