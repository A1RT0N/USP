append([], L2, L2).
append([H|T], L2, [H|T2]) :- append(T, L2, T2).

reverse([],[]).  %reverse of empty is empty - base case
reverse([H|T], RevList):-
    reverse(T, RevT), append(RevT, [H], RevList).  %concatenation