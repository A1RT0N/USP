%número de elementos
numero([], 0).
numero([_|T], Resposta) :-
    numero(T, N),
    Resposta is N + 1.

%maior elemento
maior([], Acc, Acc).
maior([H|T], Acc, Resposta) :- H > Acc, maior(T, H, Resposta).
maior([_|T], Acc, Resposta) :- maior(T, Acc, Resposta). 

maior2([], Acc, Acc).
maior2([H|T], Acc, Resposta) :- NovoMaior is max(H, Acc), maior2(T, NovoMaior, Resposta).

maior3([H], H).
maior3([H|T], Resposta) :- 
    maior3(T, MaxTail),
    Resposta is max(H, MaxTail).

%menor elemento
menor([H], H).
menor([H|T], Resposta) :-
    menor(T, MinTail),
    Resposta is min(H, MinTail).

%append
append([], L2, L2).
append([H|T], L2, [H|T2]) :- append(T, L2, T2).

%inverter
inverter([H], [H]).
inverter([H|T], NovaLista) :-
    inverter(T, CaldaInvertida),
    append(CaldaInvertida, [H], NovaLista).

inverter2(Lista, ListaInvertida) :- inverter2(Lista, [], ListaInvertida).
inverter2([], ListaInvertida, ListaInvertida).
inverter2([H|T], ListaTemporaria, ListaInvertida) :-
    inverter2(T, [H|ListaTemporaria], ListaInvertida).

%pertence
pertence(X, [X|_]).
pertence(X, [_|T]) :- pertence(X, T).

%remover
remover(X, [X|T], T).
remover(X, [H|T], Resposta) :-
    remover(X, T, NovaLista),
    Resposta is [H|NovaLista].