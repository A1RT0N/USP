%insertion sort
predicado([], []).
predicado([X|Xs], Ys) :- 
    predicado(Xs, Zs),
    regra(X, Zs, Ys).

regra(X, [], [X]).
regra(X, [Y|Ys], [X,Y|Ys]) :- X =< Y.
regra(X, [Y|Ys], [Y|Zs]) :- X > Y, 
    regra(X, Ys, Zs).
