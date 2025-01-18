pertence(X, [X|_]).
pertence(X, [H|T]) :-
    pertence(X, T).