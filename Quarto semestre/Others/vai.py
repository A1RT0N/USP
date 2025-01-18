# Corrigir a ortografia, gramática, erros de pontuação. Provavelmente, vai ter palavras como alcançá-la (que vai ter um travessão no lugar do hífen), corrigir também, pois na hora de aplicar o travessão, ele aplicou em tudo. 


import language_tool_python
from docx import Document

# Inicializar o LanguageTool para revisão em português
tool = language_tool_python.LanguageTool('pt-BR')

# Abrir o documento .docx
documento = Document('/home/ayrton/Documents/Others/livro_corrigido.docx')

# Armazenar alterações
alteracoes = []

# Iterar por todos os parágrafos e revisar o texto
for i, paragrafo in enumerate(documento.paragraphs):
    if paragrafo.text.strip():  # Ignorar parágrafos vazios
        texto_original = paragrafo.text
        # Fazer a revisão gramatical do texto
        matches = tool.check(texto_original)

        # Aplicar correções
        texto_corrigido = language_tool_python.utils.correct(texto_original, matches)

        # Se houve alguma alteração, salvar e registrar
        if texto_corrigido != texto_original:
            alteracoes.append((i + 1, texto_original, texto_corrigido))
            paragrafo.text = texto_corrigido

# Salvar o documento corrigido
documento.save('/home/ayrton/Documents/Others/livro_revisado.docx')

# Mostrar as alterações realizadas
for alteracao in alteracoes:
    paragrafo, texto_antigo, texto_novo = alteracao
    print(f"Alteração no parágrafo {paragrafo}:\nTexto Original: '{texto_antigo}'\nTexto Corrigido: '{texto_novo}'\n")
