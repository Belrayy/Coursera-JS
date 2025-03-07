import urllib.request
import json

url = input('Enter location: ')
if len(url) < 1:
    url = 'http://py4e-data.dr-chuck.net/comments_42.json'

print('Retrieving', url)
uh = urllib.request.urlopen(url)
data = uh.read()
print('Retrieved', len(data), 'characters')

info = json.loads(data)

total = 0
count = 0
for item in info['comments']:
    total += int(item['count'])
    count += 1

print('Count:', count)
print('Sum:', total)