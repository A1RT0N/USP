import numpy as np
import networkx as nx

def perron_frobenius_conditions(adj_matrix):

    if np.min(adj_matrix) < 0:
        return False
    
    G = nx.from_numpy_array(adj_matrix, create_using=nx.DiGraph)
    if not nx.is_strongly_connected(G):
        return False
    
    return True


def find_central_vertex(n, edges, s):
    # Criamos o grafo direcionado
    G = nx.DiGraph()
    G.add_weighted_edges_from(edges)
    nodelist = list(G.nodes)
    
    # Criamos a matriz de adjacência
    adj_matrix = nx.to_numpy_array(G, nodelist=nodelist)
    
    # Aplicamos a transformação de escala
    adj_matrix *= s

    # Verificação das condições do Teorema de Perron-Frobenius
    if not perron_frobenius_conditions(adj_matrix):
        return "Bixo SemVerTonha"

    # Normalizamos a matriz de adjacência para evitar problemas numéricos
    norm = np.linalg.norm(adj_matrix)
    if norm != 0:
        adj_matrix /= norm

    # Cálculamos os autovalores e autovetores
    vals, vecs = np.linalg.eig(adj_matrix)

    # Encontramos o índice do autovalor dominante (o de maior valor em módulo,
    # mas nesse caso, positivo) para encontrar o autovetor dominante (associado
    # a esse autovalor)
    dominant_index = np.argmax(np.real(vals))
    centrality_vector = np.real(vecs[:, dominant_index])

    # Identificamos o vértice mais central
    most_central_node = nodelist[np.argmax(centrality_vector)]
    return most_central_node

if __name__ == "__main__":
    # Leitura dos dados de entrada
    n, m = map(int, input().split())  
    edges = [tuple(map(int, input().split())) for _ in range(m)]  
    s = float(input())  

    # Encontramos o vértice mais central após a transformação de escala
    result = find_central_vertex(n, edges, s)
    print(result)