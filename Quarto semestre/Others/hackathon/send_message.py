from twilio.rest import Client
from datetime import datetime
import pandas as pd
account_sid = 'AC5ab923c6484d8d1e464183c84f2b610b'  # Account SID da Twilio
auth_token = 'e8da4affe4b02a790f1f9c8edfe6c398'    # Auth Token da Twilio
client = Client(account_sid, auth_token)

def format_game_time(iso_time):
    game_time_obj = datetime.fromisoformat(iso_time.replace("Z", "+00:00"))

    formatted_time = game_time_obj.strftime('%d de %B de %Y, às %H:%M')

    return formatted_time

def send_whatsapp_message(player_name, game_time,name, tournament_description, recipient_number):
    game_time = format_game_time(game_time)
    body_message = f"""Oi {player_name}! Seu jogo de {name} será às {game_time}. Boa sorte!
    {tournament_description}"""

    message = client.messages.create(
        body=body_message,
        from_='whatsapp:+14155238886',  # Número do Twilio
        to=f'whatsapp:{recipient_number}',

    )

    # Confirmação
    print(f'Mensagem enviada para {player_name}! ID: {message.sid}')

import requests


def refresh_access_key(refresh_key):
    url = "https://publicapi.challengermode.com/mk1/v1/auth/access_keys"
    headers = {
        "Content-Type": "application/json"
    }

    payload = {
        "refreshKey": refresh_key
    }

    response = requests.post(url, json=payload, headers=headers)

    if response.status_code == 200:
        return response.json()
    else:
        print(f"Erro: {response.status_code} - {response.text}")
        return None

def get_phone_number_from_csv(username, csv_file_path):
    df = pd.read_csv(csv_file_path)

    user_row = df.loc[df['username'] == username]

    if not user_row.empty:
        return user_row['phonenumber'].values[0]
    else:
        return None

csv_file_path = 'usuarios.csv'


def get_tournament_details():
    url = "https://publicapi.challengermode.com/graphql"
    refresh_key = "YjA0NzI0YjM4NjEzNDBhOWE4ZDMwOGRjZTg2MTFjNjJyQ2ZBc1BGbUdtWmhsVVp4clF1QmFpRW1keHZaQlBjdw=="
    refresh_key2 = "NGI3NWU2YTcyNDg1NDcxM2E4ZDQwOGRjZTg2MTFjNjJSR1RLY0R0UFNKV0tTRnFsbkxXUEt4ekxUWVROWGxUYQ=="
    access_key_response = refresh_access_key(refresh_key2)
    if access_key_response:
        api_key = access_key_response["value"]
        # print("Access Key:", result)


    tournament_id = "c5fb4ab0-940b-4949-9a0b-08dcdb51c8a4"
    headers = {
        "Authorization": f"Bearer {api_key}",
        "Content-Type": "application/json"
    }

    query = """
    query {
      tournament(tournamentId: "%s") {
        schedule {
          scheduledStartTimeAt
        }
        name
        description
        stages {
          lineupCount
        }
        attendance {
          signups {
            lineupCount
            lineups {
              members {
                gameAccountId
                captain
                user {
                  username
                }
              }
            }
          }
        }
      }
    }
    """ % tournament_id

    # Fazendo a requisição à API
    response = requests.post(
        url,
        json={"query": query},
        headers=headers
    )

    # Checando se a requisição foi bem-sucedida
    if response.status_code == 200:
        # Parsing da resposta JSON
        data = response.json()

        # Imprimindo a estrutura completa da resposta para depuração
        print("Resposta da API:", data)

        # Acessando o torneio
        tournament = data['data']['tournament']

        # Exibindo as informações do torneio
        print("Tournament Description:", tournament['description'])
        name = tournament['name']
        # tournament_description = tournament['description']
        tournament_description = "União CusQueijo"
        print("Scheduled Start Time:", tournament['schedule']['scheduledStartTimeAt'])

        print("Stages Lineup Counts:")
        for stage in tournament['stages']:
            print(f"- Lineup Count: {stage['lineupCount']}")

        print("Attendance Signups:")
        signups = tournament['attendance']['signups']

        # Acessando dados de signups
        print(f"Lineup Count: {signups['lineupCount']}")
        for lineup in signups['lineups']:
            print(" Lineup Members:")
            for member in lineup['members']:
              player_name = member['user']['username']
              game_time = tournament['schedule']['scheduledStartTimeAt']
              recipient_number = "+5519996401902"  # Exemplo: caso o ID seja o número do celular
              recipient_number = get_phone_number_from_csv(player_name, csv_file_path)
              print()
              print(f"  - Username: {member['user']['username']}, Captain: {'Yes' if member['captain'] else 'No'}, Number: {recipient_number}")
              if recipient_number:
                  send_whatsapp_message(player_name, game_time,name, tournament_description, recipient_number)

    else:
        print(f"Erro: {response.status_code} - {response.text}")


tournament_details = get_tournament_details()