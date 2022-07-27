data = {'coord': {'lon': 75.8167, 'lat': 26.9167},
        'weather': [{'id': 721, 'main': 'Haze', 'description': 'haze', 'icon': '50d'}],
        'base': 'stations',
        'main': {'temp': 301.77, 'feels_like': 308.7, 'temp_min': 301.77, 'temp_max': 301.77, 'pressure': 1008, 'humidity': 89},
        'visibility': 4000,
        'wind': {'speed': 5.14, 'deg': 230},
        'clouds': {'all': 75},
        'dt': 1658907818,
        'sys': {'type': 1, 'id': 9170, 'country': 'IN', 'sunrise': 1658881092, 'sunset': 1658929682},
        'timezone': 19800,
        'id':1269515,
        'name': 'Jaipur',
        'cod': 200}

main = data['weather']
main = main[0]
for i,j in main.items():
    print(i,j)
print(data['clouds'])
