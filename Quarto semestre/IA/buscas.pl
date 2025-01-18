%grafo
aresta(a, b).
aresta(a, c).
aresta(b, d).
aresta(c, d).
aresta(c, e).
aresta(d, e).

%------------auxiliares------------

%regra para ver se dois nós estão conectados entre si
conectado(X,Y) :- aresta(X, Y); aresta(Y, X).

%regra para fazer a concatenação de duas listas
append([], L2, L2).
append([H|T], L2, [H|T1]) :- append(T, L2, T1).

%regra que vai chamar alguma busca
busca(A, B, Caminho) :- dfs([[A]], B, Caminho).

%regra auxiliar que pega todos os filhos de um nó dado uma lista de nós já visitados
todos_filhosMeu(A, CaminhoParcial, L) :-
    findall(X, (conectado(A, X), not(member(X, CaminhoParcial))), L).

todos_filhos(A, Resto, L) :-
    findall([X, A|Resto], (conectado(A, X), not(member(X, Resto))), L).

%------------buscas------------

%dfs alenu
dfs([[Objetivo|Resto] | Outros], Objetivo, [Objetivo|Resto]).
dfs([[A|Resto] | Outros], Objetivo, Caminho) :-
    todos_filhos(A, Resto, L),
    append(L, Outros, NovaLista),
    dfs(NovaLista,  Objetivo, Caminho).

%dfs alenu 2
dfs2(B, B, Caminho, Caminho).
dfs2(A, B, CaminhoParcial, Caminho) :-
    conectado(A, Proximo),
    not(member(Proximo, CaminhoParcial)),
    dfs2(Proximo, B, [A|CaminhoParcial], Caminho).

%bfs alneu
bfs([[Objetivo|Resto] | Outros], Objetivo, [Objetivo|Resto]).

bfs([[A|Resto] | Outros], Objetivo, Caminho) :-
    todos_filhos(A, Resto, Filhos),
    append(Outros, Filhos, NovaLista),
    bfs(NovaLista, Objetivo, Caminho).

%Busca em profundidade
%menos eficiente, porém ordem correta
busca_profundidade_OrdemNormal(B, B, Caminho, Caminho).
busca_profundidade_OrdemNormal(A, B, CaminhoParcial, Caminho) :- 
    conectado(A, Proximo), 
    not(member(Proximo, CaminhoParcial)),
    append(CaminhoParcial, [Proximo], NovoCaminhoParcial),
    busca_profundidade_OrdemNormal(Proximo, B, NovoCaminhoParcial, Caminho).


%Busca em profundidade
dfs3([[Objetivo|CaminhoParcial] | Lista], Objetivo, [Objetivo|CaminhoParcial]).
dfs3([[A|CaminhoParcial] | Lista], Objetivo, Caminho) :-
    todos_filhosMeu(A, CaminhoParcial, Filhos),
    append(Lista, Filhos, NovaLista),
    dfs3(NovaLista, Objetivo, Caminho).


%regra auxiliar que dado uma lista de nós e uma lista de nós ja visitados retorna o primeiro nó da lista de tal forma que esse nó não está na lista de nós já visitados
nao_visitado([H|T], Visitados, H) :- not(member(H, Visitados)).
nao_visitado([H|T], Visitados, Retorno) :- nao_visitado(T, Visitados, Retorno). 

%busca em largura
busca_largura(B, B, Lista, Caminho, Caminho). %caso base
busca_largura(A, B, Lista, CaminhoParcial, Caminho) :-
    todos_filhosMeu(A, CaminhoParcial, Filhos), %pega todos os filhos que não ainda não foram visitados
    append(Lista, Filhos, NovaLista), %adiciona os novos filhos no fim da lista 
    nao_visitado(NovaLista, CaminhoParcial, Proximo), %pega o primeiro cara da lista que ainda não foi visitado
    append(CaminhoParcial, [Proximo], NovoCaminhoParcial), %adiciona o próximo cara na lista de nós visitados
    busca_largura(Proximo, B, NovaLista, NovoCaminhoParcial, Caminho). %faz a chamada recursiva


bfs2([B|Resto], B, CaminhoParcial, [B|CaminhoParcial]).
bfs2([A|Resto], B, CaminhoParcial, Caminho) :-
    todos_filhosMeu(A, CaminhoParcial, Filhos),
    append(Resto, Filhos, NovaLista),
    bfs2(NovaLista, B, [A|CaminhoParcial], Caminho).