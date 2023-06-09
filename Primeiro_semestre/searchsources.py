from langchain.agents import Tool
from langchain.memory import ConversationBufferMemory
from langchain.chat_models import ChatOpenAI
from langchain.utilities import SerpAPIWrapper
from langchain.agents import initialize_agent
from langchain.agents import AgentType
import os
import openai
from langchain.llms import OpenAI
from langchain.utilities import GoogleSearchAPIWrapper
from langchain.tools import BaseTool
from langchain.agents import initialize_agent
from googleapiclient.discovery import build 


os.environ["GOOGLE_CSE_ID"] = "e5cd86bad068f4cbd"
os.environ["GOOGLE_API_KEY"] = "AIzaSyCR2of1o1P8WluUVQuOxAQhvv9kzY6HwVc"
linkList =[]

from googleapiclient.discovery import build

class GoogleSearch():
    def __init__(self):
        self.service = build(
            "customsearch", "v1", developerKey=os.environ.get("GOOGLE_API_KEY")
        )

    def search(self, query):
        response = (
            self.service.cse()
            .list(
                q=query,
                cx=os.environ.get("GOOGLE_CSE_ID"),
            )
            .execute()
        )
        return response['items']


class CustomSearchTool(BaseTool):
    name = "SearchEngine"
    description = (
        "Use esta ferramenta para responder a perguntas sobre as notícias e eventos, bem como sobre idades e pessoas famosas solicitadas para obter os links e imprimi-los para o usuário. Traga respostas completas e grandes sempre."
        "Esta ferramenta dá-lhe acesso a um motor de busca para questões gerais."
    )

    def _run(self, query: str) -> str:
        """Use the tool."""
        google_search = GoogleSearch()
        results = google_search.search(query)

        response_with_links = ''

        for result in results:
            response_with_links += f"Link: {result['link']}\n"
            linkList.append(result['link'])

            response_with_links += f"Title: {result['title']}\n"
            response_with_links += f"Content: {result['snippet']}\n\n"
            
        return response_with_links

    async def _arun(self, query: str) -> str:
        """Use the tool asynchronously."""
        return self._run(query)  # provide a simple synchronous implementation





openai.api_key = os.environ.get("OPENAI_API_KEY")
llm = OpenAI(temperature=0)
memory = ConversationBufferMemory(memory_key="chat_history", return_messages=True)

tools = [CustomSearchTool()]


llm=OpenAI(temperature=0)
agent_chain = initialize_agent(tools, llm, agent=AgentType.CONVERSATIONAL_REACT_DESCRIPTION, verbose=True, memory=memory)
resposta = " "
pergunta = " "

while pergunta != "exit":
    pergunta = input("Digite sua pergunta: ")
    resposta = agent_chain.run(input=pergunta)
    contador=0

    while contador < 4:
        print("Link: ", linkList[contador])
        contador+=1

    linkList.clear()

