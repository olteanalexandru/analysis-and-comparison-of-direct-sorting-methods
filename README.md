You are required to compare the three sorting algorithms, in the best, average and worst
cases. Remember that for the average case you have to repeat the measurements m times
(m=5 should suffice) and report their average; also for the average case, make sure you
always use the same input sequence for all three sorting methods – to make the

1comparison fair; make sure you know how to generate the best/worst case input
sequences for all three methods.
2. This is how the analysis should be performed for a sorting method, in any of the three
cases (best, average and worst):
- vary the dimension of the input array (n) between [100…10000], with an increment
of maximum 500 (we suggest 100);
- for each dimension, generate the appropriate input sequence for the sorting method;
run the sorting method counting the operations (i.e. number of assignments, number
of comparisons and their sum).
! Only the assignments („=”) and comparisons („<”,”==”,”>”,”!=”) which are
performed on the input structure and its corresponding auxiliary variables matter.
3. For each analysis case (best, average and worst), generate charts which compare the
three methods; use different charts for the number of comparisons, number of
assignments and total number of operations. If one of the curves cannot be visualized
correctly because the others have a larger growth rate (e.g. a linear function might seem
constant when placed on the same chart with a quadratic function), place that curve on a
separate chart as well. Name your charts and the curves on each chart appropriately.
4. Interpret the charts and write your observations in the header (block comments) section at
the beginning of your main .cpp file.
5. Prepare a demo for each algorithm implemented