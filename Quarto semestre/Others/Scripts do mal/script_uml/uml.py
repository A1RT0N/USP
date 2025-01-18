import pyautogui
import time


posicao_inicial = (573,1036)

posicao_clique_entrar = (1569, 441)

posicao_menu_sair = (1486,140)

posicao_sair = (1373, 218)


pyautogui.click(posicao_inicial)

time.sleep(1)

for x in range(950):
    pyautogui.click(posicao_clique_entrar)
    
    time.sleep(2)
    
    pyautogui.click(posicao_menu_sair)
    
    time.sleep(1)
    
    pyautogui.click(posicao_sair)
    
    time.sleep(2)

# time.sleep(5)
# print(pyautogui.position())
    
# Point(x=514, y=1073), Point(x=1521, y=467), Point(x=1495, y=176), Point(x=1395, y=256)
