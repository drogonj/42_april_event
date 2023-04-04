import requests
#Permet d'envoyer des requetes a des URL

if __name__ == "__main__":
    name = input("Enter the name of a Pokemon: ")
    url = "https://pokeapi.co/api/v2/"
    res = requests.get(url + "pokemon/" + name.lower())

    if res.status_code != 200:
        print(f"Error: can't get informations for this pokemon")
    else:
        data = res.json()
        print(f"Name: {data['name'].capitalize()}")
        print("Abilities:")
        for ability in data['abilities']:
            print(f"- {ability['ability']['name'].capitalize().replace('-', ' ')}")
