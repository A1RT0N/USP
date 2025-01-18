aresta(a,b).
aresta(a,c). 
aresta(a,d). 
aresta(a,e). 
aresta(d,j).
aresta(c,f). 
aresta(c,g). 
aresta(f,h). 
aresta(e,k). 
aresta(f,i).
aresta(x,y). 
aresta(y,z). 
aresta(z,x). 
aresta(y,u). 
aresta(z,v).

conectadoLoop(X, Y) :- aresta(X, Y).
conectadoLoop(X, Y) :- aresta(X, Z), conectadoLoop(Z, Y).

conectado(X, Y) :- aresta(X, Y).
conectado(X, Y) :- conectado(X, Y, []).
conectado(X, Y, Lista) :-
    aresta(X, Z),
    not(member(Z, Lista)),
    conectado(Z, Y, [Z|Lista]).

