import pandas as pd

def main():
    # le os inteiros n1, n2, n3, n4 da entrada
    n1, n2, n3, n4 = map(int, input().split())
    
    # le o arquivo CSV com nomes das colunas especificados
    df = pd.read_csv('dados.csv', header=None, names=['Country', 'Confirmed', 'Deaths', 'Recovery', 'Active'])
    
    # exibe os nomes das colunas para verificação
    print("", df.columns)
    
    # soma de Active onde confirmed >= n1
    active_sum = df[df['Confirmed'] >= n1]['Active'].sum()
    
    # soma das Deaths dos n3 países com menores valores de Confirmed dentre os n2 países com maiores valores de Active
    top_n2_active = df.nlargest(n2, 'Active')
    top_n2_active_sorted_by_confirmed = top_n2_active.nsmallest(n3, 'Confirmed')
    deaths_sum = top_n2_active_sorted_by_confirmed['Deaths'].sum()
    
    # os n4 países com os maiores valores de "Confirmed" em ordem alfabética
    top_n4_confirmed = df.nlargest(n4, 'Confirmed')
    top_n4_confirmed_sorted = top_n4_confirmed.sort_values('Country')['Country']
    
    # imprime os dados requisitados
    print(active_sum)
    print(deaths_sum)
    for country in top_n4_confirmed_sorted:
        print(country)

if __name__ == "__main__":
    main()